# Demo 08: SLAM and Navigation 2

## Goal

Make a robot build a map first, then navigate autonomously inside that map.

## Concepts

- SLAM
- `slam_toolbox`
- Navigation 2
- `map`, `odom`, `base_link`
- Costmap
- Planner
- Controller
- Waypoint navigation

## Recommended Environment

Use Ubuntu or WSL2. Nav2 has the best documentation, dependencies, and examples on Linux.

## Mapping Flow

1. Start a simulated or physical robot.
2. Start `slam_toolbox`.
3. Drive the robot around the environment.
4. Save the map.

Typical command direction:

```bash
ros2 launch slam_toolbox online_async_launch.py
ros2 run nav2_map_server map_saver_cli -f my_map
```

## Navigation Flow

1. Start the map server.
2. Start localization.
3. Start Nav2.
4. Set the initial pose in RViz.
5. Send a navigation goal.

## Key Idea

SLAM answers "where does the map come from?" Localization answers "where is the robot?" Nav2 answers "how should the robot reach the goal?" All three depend on matching TF and correct parameters.

