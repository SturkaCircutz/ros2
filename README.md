# ROS 2 ROSbot Brightness Demo

This workspace contains one ROS 2 package, `tutorial_pkg`.

The package builds a C++ node named `my_first_node`. The node subscribes to a camera image topic, calculates the average brightness of each image, prints the result, and publishes the brightness as a `std_msgs/msg/UInt8` message on `/brightness`.

## Package Contents

```text
tutorial_pkg/
  CMakeLists.txt
  package.xml
  launch/
    my_launch_file.yaml
  src/
    my_first_node.cpp
```

## What The Node Does

Input topic:

```text
/image
```

Output topic:

```text
/brightness
```

The launch file remaps `/image` to the ROSbot simulator camera topic:

```text
/camera/color/image_raw
```

The launch file also sets:

```text
timer_period_s = 2
```

If the node is run without the launch file, the default timer period in code is `5` seconds.

## Build

Build from the workspace root:

```bash
cd ~/ros2
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select tutorial_pkg
source install/setup.bash
```

## Run With Launch File

```bash
ros2 launch tutorial_pkg my_launch_file.yaml
```

## Run With ROSbot Simulator

The ROSbot simulator image is ROS 2 Humble, so run this node in a Humble container when using the simulator.

Start the simulator:

```bash
cd ~/rosbot-xl-docker/demo
sg docker -c "docker compose -f compose.simulation.yaml up"
```

In another terminal, run the node:

```bash
cd ~/ros2
sg docker -c "docker run --rm --network host --ipc host -v /home/jiawen/ros2:/ws -w /ws ros:humble-ros-base bash -lc 'source /opt/ros/humble/setup.bash && source install_humble/setup.bash && ros2 run tutorial_pkg my_first_node --ros-args -r /image:=/camera/color/image_raw'"
```

Expected output:

```text
[my_node]: node started!
[my_node]: brightness average: 136.16
```

## Check Topics

List topics:

```bash
ros2 topic list -t
```

Echo brightness from the Humble simulator environment:

```bash
sg docker -c "docker exec demo-rosbot_xl-1 bash -lc 'source /opt/ros/humble/setup.bash && ros2 topic echo /brightness --qos-reliability reliable'"
```

Expected brightness output:

```text
data: 136
---
```

## Stop Simulator

```bash
cd ~/rosbot-xl-docker/demo
sg docker -c "docker compose -f compose.simulation.yaml down"
```
