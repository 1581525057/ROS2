import ast
from pathlib import Path


def test_main_instantiates_patrol_server_node():
    source_path = Path(__file__).parents[1] / 'patrol_service_demo' / 'patrol_server.py'
    tree = ast.parse(source_path.read_text())

    main_func = next(
        node for node in tree.body
        if isinstance(node, ast.FunctionDef) and node.name == 'main'
    )
    node_assignment = next(
        node for node in ast.walk(main_func)
        if isinstance(node, ast.Assign)
        and any(isinstance(target, ast.Name) and target.id == 'node'
                for target in node.targets)
    )

    assert isinstance(node_assignment.value, ast.Call)
    assert isinstance(node_assignment.value.func, ast.Name)
    assert node_assignment.value.func.id == 'PatrolServer'


def test_service_handle_does_not_overwrite_node_services_property():
    source_path = Path(__file__).parents[1] / 'patrol_service_demo' / 'patrol_server.py'
    tree = ast.parse(source_path.read_text())

    assigned_attributes = [
        node.attr for node in ast.walk(tree)
        if isinstance(node, ast.Attribute)
        and isinstance(node.ctx, ast.Store)
        and isinstance(node.value, ast.Name)
        and node.value.id == 'self'
    ]

    assert 'services' not in assigned_attributes
