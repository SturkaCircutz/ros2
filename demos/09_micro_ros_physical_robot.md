# Demo 09: Physical Robot and micro-ROS

## Goal

Understand how a physical mobile robot connects to ROS 2.

## Concepts

- Microcontroller
- Motor driver
- Encoder
- IMU
- Ultrasonic sensor or lidar
- PID
- Odometry
- micro-ROS

## System Structure

```text
ROS 2 computer
  |
  | cmd_vel / odom / sensor topics
  |
micro-ROS Agent
  |
  | serial / udp
  |
microcontroller board
  |
  | PWM / encoder / I2C / UART
  |
motors, sensors, IMU
```

## Minimal Experiment Order

1. Blink an LED to confirm the microcontroller development environment works.
2. Read an ultrasonic sensor or IMU.
3. Drive a motor.
4. Read encoder speed.
5. Add PID so each wheel can track a target speed.
6. Implement differential-drive forward and inverse kinematics.
7. Publish `/odom`.
8. Subscribe to `/cmd_vel`.
9. Add lidar and try mapping and navigation.

## Key Idea

A physical robot is not only ROS 2 nodes. You also need to handle motors, power, sensors, serial communication, timing, and error. micro-ROS lets a microcontroller become part of the ROS 2 graph.

