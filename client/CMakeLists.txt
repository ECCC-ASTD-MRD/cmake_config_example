cmake_minimum_required(VERSION 3.20)

project(pontClient DESCRIPTION "A client to test transitive dependencies" VERSION 0.0.1 LANGUAGES C)

set(CMAKE_SKIP_RPATH TRUE)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

find_package(pont REQUIRED)

add_executable(client src/client.c)
target_link_libraries(client PRIVATE pont::pont)
