cmake_minimum_required(VERSION 4.0)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(openglshowcase)

add_executable(openglshowcase src/main.cpp)
target_sources(openglshowcase PUBLIC src/general.cpp src/imgui.cpp src/input.cpp src/types.cpp src/Triangle.cpp
    src/Rectangle.cpp src/Camera.cpp)

add_library(openglshowcaselib STATIC src/glad.c)

target_include_directories(openglshowcaselib PUBLIC include)
target_include_directories(openglshowcaselib PUBLIC src/lib)

file(GLOB IMGUI imgui/*.cpp imgui/*.h imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_glfw.h
    imgui/backends/imgui_impl_opengl3.cpp imgui/backend/imgui_impl_opengl3.h)
set(IMGUI_SRC ${IMGUI})
add_library(imgui STATIC ${IMGUI_SRC})
target_include_directories(imgui PUBLIC imgui imgui/backends)

target_link_libraries(openglshowcase PUBLIC imgui)
target_link_libraries(openglshowcase PUBLIC openglshowcaselib)
target_link_libraries(openglshowcase PUBLIC glfw)
