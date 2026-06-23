from setuptools import find_packages, setup

package_name = 'patrol_service_demo'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='li',
    maintainer_email='1581525057@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'patrol_server = patrol_service_demo.patrol_server:main',
            'patrol_client = patrol_service_demo.patrol_client:main',
            'parameter_event_watcher = patrol_service_demo.parameter_event_watcher:main',
            'remote_param_setter = patrol_service_demo.remote_param_setter:main',
        ],
    },
)
