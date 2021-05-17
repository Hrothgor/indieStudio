cmake_minimum_required(VERSION 3.14)
project(my_project)

find_package(raylib 2.5.0 REQUIRED) # Requires at least version 2.5.0

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE my_project_src "src/*.cpp")
SET(CMAKE_CXX_FLAGS  "-std=c++17 -g3 -Ofast -pthread")
add_executable(my_project ${my_project_src})

target_link_libraries(my_project raylib)
