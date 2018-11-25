cmake_minimum_required(VERSION 2.8.3)
project(assessment)

find_package(catkin REQUIRED COMPONENTS 
    roscpp
    std_msgs
    geometry_msgs
    tf
    sensor_msgs
    cv_bridge
    image_transport
)
find_package(OpenCV REQUIRED)

catkin_package()
include_directories(${catkin_INCLUDE_DIRS})


add_executable(task1 src/task1.cpp)
target_link_libraries(task1 ${catkin_LIBRARIES})

add_executable(goals src/goals)
target_link_libraries(goals ${catkin_LIBRARIES})

add_executable(t2 src/t2)
target_link_libraries(t2 ${catkin_LIBRARIES})

add_executable(task3 src/task3)
target_link_libraries(task3 ${catkin_LIBRARIES})

add_executable(t3 src/t3)
target_link_libraries(t3 ${catkin_LIBRARIES})

add_executable(task5 src/task5)
target_link_libraries(task5 ${catkin_LIBRARIES} ${OpenCV_LIBS})