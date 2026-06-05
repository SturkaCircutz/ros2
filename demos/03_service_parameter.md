# Demo 03: Services and Parameters

## Goal

Understand that a service is a request-response interaction, while parameters are runtime configuration values for a node.

## Concepts

- Service
- Client
- Parameter
- `ros2 service`
- `ros2 param`

## Prepare

Start turtlesim:

```bat
cd /d C:\pixi_ws
pixi shell
call C:\pixi_ws\ros2-windows\local_setup.bat
ros2 run turtlesim turtlesim_node
```

## Service Experiment

List services:

```bat
ros2 service list
```

Spawn a second turtle:

```bat
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2.0, y: 2.0, theta: 0.0, name: 'turtle2'}"
```

Clear the drawing trail:

```bat
ros2 service call /clear std_srvs/srv/Empty "{}"
```

## Parameter Experiment

List and read parameters:

```bat
ros2 param list
ros2 param get /turtlesim background_r
```

Change the background color:

```bat
ros2 param set /turtlesim background_r 20
ros2 param set /turtlesim background_g 80
ros2 param set /turtlesim background_b 120
ros2 service call /clear std_srvs/srv/Empty "{}"
```

## Key Idea

Topics are good for continuous data, services are good for one-time actions, and parameters are good for configuration. Real robot systems use all three together.

