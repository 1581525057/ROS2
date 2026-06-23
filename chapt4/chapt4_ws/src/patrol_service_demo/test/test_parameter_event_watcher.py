import importlib
import os
import subprocess
import sys
from pathlib import Path


def test_parameter_event_watcher_module_imports():
    package_root = Path(__file__).parents[1]
    sys.path.insert(0, str(package_root))
    try:
        watcher = importlib.import_module(
            'patrol_service_demo.parameter_event_watcher')
    finally:
        sys.path.remove(str(package_root))

    assert watcher.ParameterEvent.__module__ == 'rcl_interfaces.msg._parameter_event'


def test_parameter_event_watcher_stops_without_shutdown_error():
    package_root = Path(__file__).parents[1]
    environment = os.environ.copy()
    environment['PYTHONPATH'] = os.pathsep.join(
        (str(package_root), environment.get('PYTHONPATH', '')))

    result = subprocess.run(
        [
            'timeout', '--preserve-status', '1', sys.executable, '-c',
            'from patrol_service_demo.parameter_event_watcher import main; main()',
        ],
        capture_output=True,
        cwd=package_root,
        env=environment,
        text=True,
    )

    assert result.returncode == 0, result.stderr
