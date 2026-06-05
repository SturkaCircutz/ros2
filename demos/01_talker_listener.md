# Demo 01: Basic Publisher and Subscriber

## Goal

Run the two classic ROS 2 demo nodes: `talker` publishes messages, and `listener` receives them.

## Concepts

- Node
- Topic
- Publisher
- Subscriber
- `ros2 run`

## Run It

First Command Prompt:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
ros2 run demo_nodes_cpp talker
```

Second Command Prompt:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
ros2 run demo_nodes_py listener
```

## What To Observe

The first window publishes messages:

```text
Publishing: 'Hello World: 1'
```

The second window receives them:

```text
I heard: [Hello World: 1]
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

