from setuptools import find_packages, setup

package_name = 'yezi_robot'

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
    maintainer='yezi',
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
            'yezi_control = yezi_robot.yezi_control:main',
            'yezi_robot = yezi_robot.yezi_robot:main'
        ],
    },
)
