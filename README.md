
Event and Frame based Visual Odometry (MC-VEO)
=============
This is the Rock component (equivalent to a ROS node) which uses the
C++ [MC-VEO library](https://github.com/huangfeng95/slam-MC-VEO) to create a Task. 

License
-------
See LICENSE file


Installation
------------
The easiest way to build and install this component is to use Rock's build system.
See [this page](http://rock-robotics.org/documentation/installation.html)
on how to install Rock. You can use the [MC-VEO builconf](https://github.com/huangfeng95/MC-VEO-buildconf)
which tells you how to install and use the component from scratch. There is also the opction to directly
use this component in a Docker container.

This component is a basic Task class which wraps the MC-VEO library in an RTT component style. Therfore, it depends
on RTT communication layer in which Rock is built on top. It should be straight forward to remove this dependency and use
the Task class as a single main program. 

Dependencies
-----------------
Dependencies are listed in the manifest file, those are:

* [base/cmake](https://github.com/rock-core/base-cmake): the CMake pure function to build this library
* [slam/MC-VEO](https://github.com/huangfeng95/slam-MC-VEO): the MC-VEO library
* [yaml-cpp](https://github.com/jbeder/yaml-cpp): YAML config parser for the configuration parameters
* [perception/frame_helper](https://github.com/rock-core/perception-frame_helper): Frame Image converter between Opencv and Rock types
* [base/orogen/types](https://github.com/rock-core/base-orogen-types): Package to expose the Rock (Robot Construction Kit) base types
* [drivers/orogen/aggregrator](https://github.com/rock-core/drivers-orogen-aggregator): This is a data stream aligner. It brings the callback functionaly to the Task class.


OROGEN file
-----------------
Tasks are defined in Orogen which is a subset of Ruby language. The orogen file (MC-VEO.orogen) defines
all the Task functionalities such as properties, input & output ports, triggering mechanism, etc..
This files is parsed by Rock in order to defined the temporary content in the .orogen folder.
You can call the orogen parser but just typing:

```console
docker@MC-VEO:~S orogen --corba MC-VEO.orogen
```

Task Standard Layout
--------------------
This directory structure follows some simple rules, to allow for generic build
processes and simplify reuse of this project. Following these rules ensures that
the Rock CMake macros automatically handle the project's build process and
install setup properly.

### MC-VEO Folder Structure

| directory         |       purpose                                                        |
| ----------------- | ------------------------------------------------------               |
| task/             | Contains the Task.cpp and Task.hpp of the [component](https://www.rock-robotics.org/documentation/orogen/task_interface.html)                  |
| .orogen/          | Contains the Task parent classes which interface with [RTT](https://www.orocos.org/rtt/)  <br> This is a temporary content folder created from MC-VEO.orogen <br> This is the folder to remove (to make Task not inherit) in order to make this an independent main program |
| build/ *          | The target directory for the build process, temporary content        |
| [MC-VEOTypes.hpp](MC-VEOTypes.hpp)      | Specific data types for the Task. These are normally types which are not available in [base-types](https://www.rock-robotics.org/documentation/orogen/task_interface.html). These are normally cofiguration struct or specific output port data types. |
| [MC-VEO.orogen](MC-VEO.orogen)        | This is the task definition file                 |
