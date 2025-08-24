cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(opengltests)

add_executable(opengltests src/main.cpp)

add_library(opengltestslib STATIC src/glad.c)

target_include_directories(opengltestslib PUBLIC include)

target_link_libraries(opengltests PUBLIC opengltestslib)
target_link_libraries(opengltests PUBLIC glfw)
