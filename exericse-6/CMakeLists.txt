cmake_minimum_required(VERSION 3.24)
project(exercise_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(exercise_6A chess.cpp)
add_executable(exercise_6B web_server.cpp)
target_link_libraries(exercise_6B ${Boost_LIBRARIES})