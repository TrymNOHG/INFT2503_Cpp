cmake_minimum_required(VERSION 3.24)
project(exercise_8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(exercise_8a exercise8a.cpp)
add_executable(exercise_8b exercise8b.cpp)