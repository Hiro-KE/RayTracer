## General
cmake_minimum_required(VERSION 3.13.4)
project(RayTracer)
 
add_executable(${PROJECT_NAME} main.cpp)

## Render
add_library(Render STATIC src/render.cpp src/hittable_list.cpp src/sphere.cpp)
target_include_directories(Render PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} Render)


## Definitions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()