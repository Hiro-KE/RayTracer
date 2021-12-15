## General
cmake_minimum_required(VERSION 3.13.4)
project(RayTracer)

## Render
add_library(Render STATIC 
                src/render.cpp 
                src/hittable_list.cpp 
                src/sphere.cpp
                src/camera.cpp
                src/material.cpp)

                
# Link Dependencies 

find_package(OpenMP REQUIRED)
target_include_directories(Render PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Render OpenMP::OpenMP_CXX)


## Definitions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(/openmp)
endif()