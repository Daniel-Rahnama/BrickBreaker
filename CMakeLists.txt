cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

project(BrickBreaker)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB src src/*.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(BrickBreaker ${src})

target_link_libraries(BrickBreaker pthread)

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(BrickBreaker ${SDL2_LIBRARIES})