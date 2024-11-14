cmake_minimum_required(VERSION 3.0.2)
project(simple_pcl_example)

# 在标准库路径中查找，找不到会报错
find_package(PCL 1.10 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(simple_pcl_example simple_pcl_example.cpp)
target_link_libraries(simple_pcl_example ${PCL_LIBRARIES})