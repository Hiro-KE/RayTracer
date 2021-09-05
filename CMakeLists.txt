cmake_minimum_required(VERSION 3.13.4)
project(RayTracer)
 
add_executable(${PROJECT_NAME} main.cpp)

## Engine
add_library(Engine STATIC src/engine.cpp)
target_include_directories(Engine PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} Engine)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()