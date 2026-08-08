from glob import glob

from setuptools import find_packages, setup

package_name = 'patrol_service__demo'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
        ('share/' + package_name + '/docs', glob('docs/*.html')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yezi',
    maintainer_email='yezi@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
        'patrol_server = patrol_service__demo.patrol_server:main',
        'partom_client = patrol_service__demo.patrol_client:main',
        'remote_param = patrol_service__demo.remote_param:main',
        ],
    },
)
