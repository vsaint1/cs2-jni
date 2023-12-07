cmake_minimum_required(VERSION 3.10)

project(engine)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_library(engine SHARED main.cpp)

set_target_properties(engine PROPERTIES OUTPUT_NAME "engine")
