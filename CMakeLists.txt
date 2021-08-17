cmake_minimum_required(VERSION 3.0.2)
project(teleop_listener)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)
# add_message_files(FILES MsgTutorial.msg)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  LIBRARIES teleop_listener
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(teleop_listener src/teleop_listener.cpp)
add_dependencies(teleop_listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(teleop_listener ${catkin_LIBRARIES})
