# Demo 04: Launch Files and ros2 bag

## Goal

Learn how to start multiple nodes together and how to record and replay ROS 2 data.

## Concepts

- Launch file
- Multi-node system
- `ros2 bag record`
- `ros2 bag play`

## Launch Example

This demo pack includes a minimal launch file:

```text
../launch/talker_listener.launch.py
```

If you have your own ROS 2 package, place this file in that package's `launch` directory and run:

```bat
ros2 launch <your_package> talker_listener.launch.py
```

If you are only learning the concept, you can still start `talker` and `listener` in two separate windows.

## Record A Bag

Start `talker`:

```bat
ros2 run demo_nodes_cpp talker
```

Open another Command Prompt and record `/chatter`:

```bat
ros2 bag record /chatter
```

Stop recording with `Ctrl + C`.

Inspect the bag:

```bat
ros2 bag info <bag_folder_name>
```

Replay it:

```bat
ros2 bag play <bag_folder_name>
```

Open another window and listen:

```bat
ros2 topic echo /chatter
```

## Key Idea

Launch files answer "how do I start the system?" Bag files answer "how do I save and replay the data?" Bag recording is extremely useful for robot debugging.

