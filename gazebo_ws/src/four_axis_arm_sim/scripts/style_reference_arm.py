"""Build reference-inspired visuals using only URDF primitives."""

from pathlib import Path
import math
import xml.etree.ElementTree as ET


URDF = Path('/home/yezi/ROS2/four_axis_arm.urdf')

COLORS = {
    'charcoal': '0.075 0.085 0.09 1',
    'black': '0.025 0.03 0.035 1',
    'graphite': '0.16 0.18 0.18 1',
    'aluminum': '0.81 0.83 0.82 1',
    'edge': '0.55 0.59 0.58 1',
    'lime': '0.76 0.98 0.16 1',
    'lime_light': '0.82 1.0 0.24 1',
}


tree = ET.parse(URDF, parser=ET.XMLParser(target=ET.TreeBuilder(insert_comments=True)))
robot = tree.getroot()
# Rebuilding the appearance is idempotent: remove visual-only fixed children
# produced by a previous run before constructing the new ones.
for child in list(robot):
    if child.tag in ('link', 'joint') and child.get('name', '').startswith('appearance__'):
        robot.remove(child)
links = {link.get('name'): link for link in robot.findall('link')}
for link in links.values():
    for old in list(link.findall('visual')):
        link.remove(old)


def visual(link, name, shape, size, xyz, color, rpy='0 0 0'):
    node = ET.SubElement(links[link], 'visual', {'name': name})
    ET.SubElement(node, 'origin', {'xyz': xyz, 'rpy': rpy})
    geometry = ET.SubElement(node, 'geometry')
    if shape == 'box':
        ET.SubElement(geometry, 'box', {'size': size})
    elif shape == 'cylinder':
        radius, length = size.split()
        ET.SubElement(geometry, 'cylinder', {'radius': radius, 'length': length})
    else:
        raise ValueError(shape)
    material = ET.SubElement(node, 'material', {'name': color})
    ET.SubElement(material, 'color', {'rgba': COLORS[color]})


def cyl(link, name, radius, length, xyz, color, rpy='0 0 0'):
    visual(link, name, 'cylinder', f'{radius:.4f} {length:.4f}', xyz, color, rpy)


def box(link, name, dimensions, xyz, color, rpy='0 0 0'):
    visual(link, name, 'box', dimensions, xyz, color, rpy)


# Low black plinth and a tall motor can like the reference image.
cyl('base_link', 'black_base', .105, .040, '0 0 0.020', 'charcoal')
cyl('base_link', 'base_top_bevel', .098, .008, '0 0 0.044', 'edge')
cyl('motor1_housing', 'vertical_motor', .060, .152, '0 0 0', 'charcoal')
cyl('motor1_housing', 'vertical_motor_cap', .060, .009, '0 0 0.078', 'black')
cyl('motor1_housing', 'vertical_motor_flange', .063, .008, '0 0 -0.077', 'aluminum')
for i in range(4):
    theta = i * math.pi / 2
    x, y = .061 * math.cos(theta), .061 * math.sin(theta)
    box('motor1_housing', f'vent_{i}', '0.008 0.013 0.042',
        f'{x:.4f} {y:.4f} -0.028', 'black', f'0 0 {theta:.5f}')

cyl('yaw_link', 'shoulder_turntable', .064, .023, '0 0 -0.029', 'aluminum')
box('yaw_link', 'shoulder_black_hub', '0.094 0.074 0.063', '0 0 -0.002', 'charcoal')
for side in (-1, 1):
    box('yaw_link', f'shoulder_cheek_{side}', '0.072 0.005 0.078',
        f'0 {side * .040:.4f} 0.003', 'aluminum')

for link, radius, length in (
    ('motor2_housing', .050, .064),
    ('motor3_housing', .043, .060),
    ('motor4_housing', .034, .047),
):
    cyl(link, 'motor_can', radius, length, '0 0 0', 'charcoal')
    cyl(link, 'motor_front_lip', radius * 1.04, .006,
        f'0 0 {length / 2 + .005:.4f}', 'aluminum')
    cyl(link, 'motor_rear_lip', radius * .97, .006,
        f'0 0 {-length / 2 - .005:.4f}', 'edge')


def arm_segment(link, length, side_z, hub_r):
    # Black actuator body stays visible between the two pale side plates.
    box(link, 'black_inner_beam', f'{length - .02:.3f} 0.052 0.061',
        f'{length / 2:.3f} 0.017 0', 'charcoal')
    box(link, 'upper_beam_edge', f'{length - .07:.3f} 0.009 0.052',
        f'{length / 2:.3f} 0.057 0', 'graphite')
    for side in (-1, 1):
        z = side * side_z
        outside = side * (side_z + .004)
        badge = side * (side_z + .015)
        # Layered pale covers and lime inserts use only URDF boxes. Their
        # thickness and offset keep them visible over the dark inner beam.
        box(link, f'white_side_plate_{side}',
            f'{length * .87:.4f} 0.084 0.006',
            f'{length * .51:.4f} 0.015 {z:.4f}', 'aluminum')
        box(link, f'white_plate_front_{side}',
            f'{length * .13:.4f} 0.059 0.006',
            f'{length * .055:.4f} 0.015 {z:.4f}', 'aluminum', '0 0 0.22')
        box(link, f'white_plate_rear_{side}',
            f'{length * .13:.4f} 0.059 0.006',
            f'{length * .945:.4f} 0.015 {z:.4f}', 'aluminum', '0 0 -0.22')
        box(link, f'lime_inlay_{side}',
            f'{length * .52:.4f} 0.032 0.004',
            f'{length * .56:.4f} 0.034 {outside:.4f}', 'lime')
        box(link, f'lime_face_{side}',
            f'{length * .47:.4f} 0.027 0.004',
            f'{length * .56:.4f} 0.026 {side * (side_z + .010):.4f}',
            'lime')
        for i in range(3):
            x = length * (.43 + i * .092)
            box(link, f'panel_diamond_{side}_{i}', '0.010 0.010 0.004',
                f'{x:.4f} 0.034 {badge:.4f}', 'charcoal', '0 0 0.7854')
        # One cover per hinge prevents the parent and child cover surfaces from
        # occupying the same plane when their joint origins coincide.
        for label, x in (('start', .015),):
            cyl(link, f'{label}_pivot_disc_{side}', hub_r, .006,
                f'{x:.4f} 0.015 {side * (side_z + .020):.4f}',
                'aluminum')
            cyl(link, f'{label}_pivot_bore_{side}', hub_r * .30, .008,
                f'{x:.4f} 0.015 {side * (side_z + .027):.4f}',
                'black')
            for i in range(6):
                theta = i * math.pi / 3
                px = x + hub_r * .66 * math.cos(theta)
                py = .015 + hub_r * .66 * math.sin(theta)
                cyl(link, f'{label}_bolt_{side}_{i}', .0028, .008,
                    f'{px:.4f} {py:.4f} {side * (side_z + .027):.4f}',
                    'edge')


arm_segment('upper_arm_link', .32, .040, .044)
arm_segment('forearm_link', .26, .035, .037)

cyl('wrist_link', 'wrist_black_housing', .034, .070, '0 0 0',
    'charcoal', '1.570796327 0 0')
cyl('wrist_link', 'wrist_front_ring', .036, .007, '0 0.039 0',
    'aluminum', '1.570796327 0 0')
box('wrist_link', 'gripper_body', '0.074 0.052 0.037',
    '0.039 0 0.010', 'charcoal')
for side in (-1, 1):
    box('wrist_link', f'jaw_{side}', '0.072 0.011 0.028',
        f'0.100 {side * .030:.4f} 0.010', 'charcoal')
    box('wrist_link', f'jaw_pad_{side}', '0.026 0.004 0.024',
        f'0.122 {side * .022:.4f} 0.010', 'graphite')
    box('wrist_link', f'jaw_lime_tip_{side}', '0.014 0.014 0.008',
        f'0.059 {side * .030:.4f} 0.030', 'lime_light')

# In RViz Humble, visual elements inside one link can inherit the material of
# its first visual. Give each colored piece its own fixed visual-only link.
# Gazebo merges these fixed links while preserving their placement.
for parent_name, parent in links.items():
    for visual_node in list(parent.findall('visual')):
        parent.remove(visual_node)
        visual_name = visual_node.get('name')
        piece_name = f'appearance__{parent_name}__{visual_name}'
        piece = ET.SubElement(robot, 'link', {'name': piece_name})
        piece.append(visual_node)
        joint = ET.SubElement(robot, 'joint', {
            'name': f'{piece_name}__fixed', 'type': 'fixed'})
        ET.SubElement(joint, 'parent', {'link': parent_name})
        ET.SubElement(joint, 'child', {'link': piece_name})
        ET.SubElement(joint, 'origin', {'xyz': '0 0 0', 'rpy': '0 0 0'})

ET.indent(tree, space='  ')
tree.write(URDF, encoding='utf-8', xml_declaration=True)
