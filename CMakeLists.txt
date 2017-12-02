cmake_minimum_required(VERSION 2.8.3)
project(GMM)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)

catkin_package(
  CATKIN_DEPENDS cv_bridge image_transport roscpp std_msgs sensor_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(gmm src/gmm.cpp)
target_link_libraries(gmm  ${OpenCV_LIBRARIES}  ${catkin_LIBRARIES})

add_executable(pub src/publisher.cpp)
target_link_libraries(pub  ${OpenCV_LIBRARIES}  ${catkin_LIBRARIES})

add_executable(sub src/subscriber.cpp)
target_link_libraries(sub  ${OpenCV_LIBRARIES}  ${catkin_LIBRARIES})
