# Demo 01: Basic Publisher and Subscriber

## Goal

Run the classic ROS 2 talker/listener pattern using source code in this repository:
the C++ `talker` publishes messages, and the Python `listener` receives them.

## Concepts

- Node
- Topic
- Publisher
- Subscriber
- `ros2 run`
- Cross-language communication

## Build It

Open your ROS 2 environment first, then build this repository:

```bat
cd /d C:\path\to\ros2_demo_pack
colcon build --symlink-install
call install\setup.bat
```

## Run It

First Command Prompt:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
cd /d C:\path\to\ros2_demo_pack
call install\setup.bat
ros2 run cpp_pubsub talker
```

Second Command Prompt:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
cd /d C:\path\to\ros2_demo_pack
call install\setup.bat
ros2 run py_pubsub listener
```

## What To Observe

The first window publishes messages:

```text
Publishing: 'Hello ROS 2: 1'
```

The second window receives them:

```text
I heard: 'Hello ROS 2: 1'
```

## Inspect The System

Open a third Command Prompt:

```bat
ros2 node list
ros2 topic list
ros2 topic echo /chatter
ros2 topic info /chatter
```

## Key Idea

`talker` and `listener` do not directly call each other. They exchange data through the `/chatter` topic. This loose coupling is one of the core ideas in ROS 2.

The C++ node and Python node can communicate because both use the same topic
name, `/chatter`, and the same message type, `std_msgs/msg/String`.
