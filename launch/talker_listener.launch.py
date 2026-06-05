from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="demo_nodes_cpp",
            executable="talker",
            name="demo_talker",
            output="screen",
        ),
        Node(
            package="demo_nodes_py",
            executable="listener",
            name="demo_listener",
            output="screen",
        ),
    ])

