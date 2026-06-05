# Demo 06: URDF Robot Model

## Goal

Use a tiny differential-drive robot model to understand URDF.

## Concepts

- Link
- Joint
- `robot_state_publisher`
- Robot model visualization in RViz
- `base_link`, wheels, caster

## Included File

This demo pack includes:

```text
../urdf/tiny_diffbot.urdf.xml
```

The model contains:

- One body link: `base_link`
- Two wheels
- One front caster support point

## Recommended Run Environment

The full URDF/RViz workflow is easier on Ubuntu or WSL2.

Typical commands:

```bash
ros2 run robot_state_publisher robot_state_publisher tiny_diffbot.urdf.xml
rviz2
```

In RViz:

- Set Fixed Frame to `base_link`.
- Add `RobotModel`.

## Key Idea

URDF describes what the robot looks like and how its parts are connected. In real projects, URDF often grows to include sensors, collision geometry, inertia, Gazebo tags, and ros2_control configuration.

