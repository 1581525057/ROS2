from glob import glob
from setuptools import find_packages, setup

package_name = 'move_action_tutorial'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ROS 2 Student',
    maintainer_email='student@example.com',
    description='Beginner-friendly Python action server and client for ROS 2.',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'move_server = move_action_tutorial.action_server:main',
            'move_client = move_action_tutorial.action_client:main',
        ],
    },
)
