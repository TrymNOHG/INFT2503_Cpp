cmake_minimum_required(VERSION 3.24)
project(exercise_4)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(exercise_4A PartA.cpp)
add_executable(exercise_4B PartB.cpp)

target_link_libraries(exercise_4B ${GTKMM_LIBRARIES})

