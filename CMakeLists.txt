cmake_minimum_required(VERSION 3.10)

project(client)

set(VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PDB_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)


add_executable(${PROJCET_NAME} WIN32 client/main.cpp)

add_subdirectory(engine)