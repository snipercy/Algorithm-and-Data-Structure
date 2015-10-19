cmake_minimum_required(VERSION 3.2)
project(PAT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 1004.cpp)
add_executable(PAT ${SOURCE_FILES} .idea/1008.cpp)