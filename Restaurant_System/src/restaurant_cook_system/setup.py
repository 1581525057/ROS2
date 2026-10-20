import os
from glob import glob

from setuptools import find_packages, setup

package_name = 'restaurant_cook_system'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # 【新增】构建时把 launch 文件安装到 install 目录，否则 ros2 launch 找不到它。
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py')),
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
            'customer_node = restaurant_cook_system.customer_node:main',
            # 【新增】注册收银台和厨房节点，使其可以通过 ros2 run 启动。
            'cashier_node = restaurant_cook_system.cashier_node:main',
            'kitchen_node = restaurant_cook_system.kitchen_node:main',
        ],
    },
)
