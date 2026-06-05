# Demo 10: Advanced ROS 2 Concepts

## Goal

Understand the ROS 2 mechanisms that often appear in engineering projects.

## Concepts

- QoS
- Executor
- Callback Group
- Lifecycle Node
- Composition
- Message Filter
- DDS

## QoS Mini Experiment

QoS controls communication behavior, such as reliability, queue depth, and whether late subscribers can receive previously published data.

Important ideas:

- Reliable: stronger delivery guarantee, useful for important data.
- Best Effort: lower overhead, useful for high-frequency sensor data.
- Transient Local: stores the last data sample for late subscribers.

Common issue: if publisher and subscriber QoS settings are incompatible, both nodes may appear to be running, but no messages are received.

## Lifecycle Nodes

Lifecycle nodes split a node into states:

```text
unconfigured -> inactive -> active -> finalized
```

This is useful for complex modules such as cameras, lidars, and navigation stacks that need clear startup and shutdown stages.

## Components And Executors

Multiple nodes can run inside one process to reduce communication overhead. Executors and callback groups control how callbacks are scheduled, run in parallel, or kept mutually exclusive.

## Key Idea

Basic ROS 2 helps your program run. Advanced ROS 2 features help your robot system become more stable, controllable, and ready for engineering use.

