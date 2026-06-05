from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_pubsub",
            executable="talker",
            name="demo_talker",
            output="screen",
        ),
        Node(
            package="py_pubsub",
            executable="listener",
            name="demo_listener",
            output="screen",
        ),
    ])
