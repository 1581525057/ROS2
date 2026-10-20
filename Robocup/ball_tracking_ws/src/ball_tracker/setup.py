from setuptools import find_packages, setup


package_name = "ball_tracker"

setup(
    name=package_name,
    version="0.1.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/launch", ["ball_tracker/ball_tracking.launch.py"]),
    ],
    install_requires=["setuptools", "pyserial>=3.5"],
    scripts=["scripts/ball_tracker_node", "scripts/ball_serial_node", "scripts/lora_keys_node"],
    zip_safe=True,
    maintainer="yezi",
    maintainer_email="yezi@example.com",
    description="YOLO ball detection and target information for a following robot.",
    license="MIT",
)
