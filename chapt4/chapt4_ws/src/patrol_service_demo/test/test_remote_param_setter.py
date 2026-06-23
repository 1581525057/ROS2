from pathlib import Path


PACKAGE_ROOT = Path(__file__).parents[1]
SOURCE_PATH = PACKAGE_ROOT / 'patrol_service_demo' / 'remote_param_setter.py'
TUTORIAL_PATH = PACKAGE_ROOT.parents[1] / 'docs' / 'service_communication_tutorial.html'


def test_remote_parameter_setter_uses_humble_set_parameters_api():
    source = SOURCE_PATH.read_text()
    tutorial = TUTORIAL_PATH.read_text()

    for content in (source, tutorial):
        assert 'from rcl_interfaces.srv import SetParameters' in content
        assert "'/patrol_server/set_parameters'" in content
        assert "'robot_name'" in content
        assert "'allow'" in content

    assert 'AsyncParameterClient' not in source
    assert 'AsyncParameterClient' not in tutorial
    assert 'rclpy.spin_until_future_complete(self, future)' in source
    assert 'rclpy.spin(node)' not in source
