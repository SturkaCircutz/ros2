# Demo 07: Gazebo and ros2_control

## Goal

Understand the simulation chain: the robot model enters Gazebo, a controller receives velocity commands, and the robot moves in a simulated world.

## Concepts

- Gazebo
- URDF/Xacro
- Sensor simulation
- ros2_control
- Differential-drive controller

## Recommended Environment

Use Ubuntu or WSL2. Native Windows ROS 2 is fine for basic communication demos, but Gazebo and Nav2 are usually smoother on Linux.

## Minimal Experiment Plan

1. Create a URDF/Xacro mobile robot model.
2. Add Gazebo tags so the model can be loaded into Gazebo.
3. Add wheels, lidar, IMU, or camera simulation.
4. Connect the robot to `ros2_control`.
5. Load a differential-drive controller.
6. Publish `/cmd_vel` and observe the robot moving.

## Command Direction

```bash
ros2 launch <robot_package> gazebo.launch.py
ros2 control list_controllers
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.2}, angular: {z: 0.5}}"
```

## Key Idea

Gazebo provides the physical world, ROS 2 provides the robot software system, and ros2_control connects software commands to actuator-style control interfaces.

