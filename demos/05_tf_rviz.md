# Demo 05: TF and RViz Coordinate Transforms

## Goal

Understand why robots need coordinate frames and how TF describes spatial relationships between frames.

## Concepts

- TF
- Static transform
- Dynamic transform
- RViz visualization
- Frame tree

## Static TF Experiment

Publish a static transform from `world` to `base_link`:

```bat
ros2 run tf2_ros static_transform_publisher 1 0 0 0 0 0 world base_link
```

Open another Command Prompt and inspect it:

```bat
ros2 run tf2_ros tf2_echo world base_link
```

## View In RViz

Start RViz:

```bat
rviz2
```

In RViz:

- Set Fixed Frame to `world`.
- Add `TF`.
- Observe `world` and `base_link`.

## Key Idea

A robot does not have just one coordinate frame. A common navigation chain is:

```text
map -> odom -> base_link -> laser
```

Nav2, SLAM, laser visualization, and path planning all depend on correct TF data. If TF is wrong, the robot may localize badly, show a shifted map, or fail to navigate.

