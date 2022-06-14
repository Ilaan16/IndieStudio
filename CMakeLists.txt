cmake_minimum_required(VERSION 3.17)

project(IndieStudio VERSION 1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules/)
FIND_PACKAGE(raylib REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB_RECURSE MAIN_SOURCE src/*.cpp)

#add_compile_options(-fsanitize=address -g)
#add_link_options(-fsanitize=address)

include_directories(src)

add_executable(indie ${MAIN_SOURCE})
TARGET_LINK_LIBRARIES(indie raylib)