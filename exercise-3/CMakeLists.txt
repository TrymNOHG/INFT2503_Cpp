cmake_minimum_required(VERSION 3.24)
project(exercise_3)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra)

add_executable(exercise_3A PartA.cpp)
add_executable(exercise_3B PartB.cpp)
add_executable(exercise_3C PartC.cpp)
add_executable(exercise_3C2 PartC2.cpp)
