from glob import glob
from setuptools import setup

package_name = 'four_axis_arm_sim'
setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml', 'README.md']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/' + package_name + '/worlds', glob('worlds/*.sdf')),
        ('share/' + package_name + '/rviz', glob('rviz/*.rviz')),
        ('share/' + package_name + '/scripts', glob('scripts/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yezi',
    maintainer_email='yezi@example.com',
    description='Gazebo Fortress simulation and ROS 2 bridge for a four-axis arm',
    license='Apache-2.0',
    entry_points={'console_scripts': ['mit_controller = four_axis_arm_sim.mit_controller:main']},
)
