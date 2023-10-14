cmake_minimum_required(VERSION 3.24)
project(exercise_7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(exercise_7a exercise7a.cpp)
add_executable(exercise_7b exercise7b.cpp)