cmake_minimum_required(VERSION 3.10)

project(engine)

set(VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_PROJECT_DIR}/build)

file(GLOB_RECURSE IMGUI_CPP  ${CMAKE_CURRENT_SOURCE_DIR}/external/includes/imgui/*.cpp)
file(GLOB_RECURSE IMGUI_HEADER  ${CMAKE_CURRENT_SOURCE_DIR}/external/includes/imgui/*.h)

add_library(engine SHARED main.cpp ${IMGUI_CPP} ${IMGUI_HEADER})

set_target_properties(engine PROPERTIES OUTPUT_NAME "engine")

include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/process)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/includes)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/lib)
target_include_directories(${PROJECT_NAME} PRIVATE $ENV{DXSDK_DIR}Include)

target_link_directories(${PROJECT_NAME} PRIVATE $ENV{DXSDK_DIR}Lib/x64)
target_link_libraries(${PROJECT_NAME} PUBLIC d3d9 d3dx9 Dwmapi ntdll)  