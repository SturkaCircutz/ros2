# Demo 02: Turtlesim Keyboard Control and Topics

## Goal

Use `turtlesim` to understand robot motion control. A keyboard node publishes velocity commands, and the turtle node subscribes to those commands and moves.

## Concepts

- Velocity commands
- Topic messages
- Message types
- `ros2 topic echo`
- `ros2 interface show`

## Run It

First Command Prompt:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
ros2 run turtlesim turtlesim_node
```

Second Command Prompt:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
ros2 run turtlesim turtle_teleop_key
```

Keep the second window focused and use the arrow keys to move the turtle.

## Observe Topics

Third Command Prompt:

```bat
ros2 topic list
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

Inspect the velocity message type:

```bat
ros2 interface show geometry_msgs/msg/Twist
```

Inspect the turtle pose message type:

```bat
ros2 interface show turtlesim/msg/Pose
```

## Key Idea

Robot motion control is often done by publishing velocity commands. For mobile robots, the common velocity topic is `/cmd_vel`, usually using `geometry_msgs/msg/Twist`.

