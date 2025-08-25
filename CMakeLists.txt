cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(opengltests)

add_executable(opengltests src/main.cpp)

add_library(opengltestslib STATIC src/glad.c)

target_include_directories(opengltestslib PUBLIC include)

file(GLOB IMGUI imgui/*.cpp imgui/*.h imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_glfw.h
    imgui/backends/imgui_impl_opengl3.cpp imgui/backend/imgui_impl_opengl3.h)
set(IMGUI_SRC ${IMGUI})
add_library(imgui STATIC ${IMGUI_SRC})
target_include_directories(imgui PUBLIC imgui imgui/backends)

target_link_libraries(opengltests PUBLIC imgui)
target_link_libraries(opengltests PUBLIC opengltestslib)
target_link_libraries(opengltests PUBLIC glfw)
