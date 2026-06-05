# ROS 2 Demo Pack

This folder turns the main ideas from the ROS 2 robotics book into 10 small demos. Each demo has a clear goal, the ROS 2 concepts it teaches, commands to try, and what you should observe.

It also includes source code for the first mixed-language demo:

- `src/cpp_pubsub`: C++ `talker` node.
- `src/py_pubsub`: Python `listener` node.

You already ran the `talker` example successfully on native Windows ROS 2, so start with demos 01-05. Demos 06 and later involve URDF, Gazebo, Navigation 2, and micro-ROS, which are usually smoother on Ubuntu or WSL2.

## Open Your ROS 2 Environment First

In Windows Command Prompt, run:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
```

If this works, check ROS 2:

```bat
ros2 --help
```

## Build The Included Source Packages

After opening your ROS 2 environment, build this repository:

```bat
cd /d C:\path\to\ros2_demo_pack
colcon build --symlink-install
call install\setup.bat
```

## Demo Order

1. [Basic Publisher and Subscriber](demos/01_talker_listener.md)
2. [Turtlesim Keyboard Control and Topics](demos/02_turtlesim_topic.md)
3. [Services and Parameters](demos/03_service_parameter.md)
4. [Launch Files and ros2 bag](demos/04_launch_bag.md)
5. [TF and RViz Coordinate Transforms](demos/05_tf_rviz.md)
6. [URDF Robot Model](demos/06_urdf_robot_model.md)
7. [Gazebo and ros2_control](demos/07_gazebo_ros2_control.md)
8. [SLAM and Navigation 2](demos/08_slam_nav2.md)
9. [Physical Robot and micro-ROS](demos/09_micro_ros_physical_robot.md)
10. [Advanced ROS 2 Concepts](demos/10_advanced_ros2.md)

## Included Small Files

- `src/cpp_pubsub/src/talker.cpp`: a C++ publisher for `/chatter`.
- `src/py_pubsub/py_pubsub/listener.py`: a Python subscriber for `/chatter`.
- `launch/talker_listener.launch.py`: a minimal launch file example.
- `urdf/tiny_diffbot.urdf.xml`: a tiny differential-drive robot model for learning links, joints, and TF.

## Suggested Learning Path

Start with communication: nodes, topics, services, and parameters.

Then learn tools: launch, bag, TF, and RViz.

After that, move into robot structure: URDF, Gazebo, and ros2_control.

Finally, study system-level concepts: SLAM, Nav2, micro-ROS, QoS, lifecycle nodes, and DDS.
