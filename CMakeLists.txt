cmake_minimum_required(VERSION 2.8)
project(ros_benchmark)

find_package(catkin)

find_package(catkin REQUIRED COMPONENTS roscpp)# actionlib)

include_directories(include)
include_directories(${catkin_INCLUDE_DIRS})

add_executable(ros_ping_node
  src/ros_ping_node.cpp
)
target_link_libraries(ros_ping_node ${catkin_LIBRARIES})

add_executable(ros_pong_node
  src/ros_pong_node.cpp
)
target_link_libraries(ros_pong_node ${catkin_LIBRARIES})

#add_executable(ros_action_ping_node
#  src/ros_action_ping_node.cpp
#)
#target_link_libraries(ros_action_ping_node ${catkin_LIBRARIES})
#
#add_executable(ros_action_pong_node
#  src/ros_action_pong_node.cpp
#)
#target_link_libraries(ros_action_pong_node ${catkin_LIBRARIES})

#add_library(ping_nodelet src/ros_ping_pong_nodelet.cpp)
