cmake_minimum_required(VERSION 3.22)

# set(CMAKE_CXX_STANDARD 17)
project(face_detection)

# OPENCV
find_package(OpenCV 4.1 REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Find all executables
include_directories(include)
file(GLOB SOURCES src/*.cpp) #src/*.h

# Add project executable
add_executable(face_detection ${SOURCES})
target_link_libraries(face_detection "${OpenCV_LIBRARIES}")
