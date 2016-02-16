cmake_minimum_required(VERSION 3.2)
project(PAT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -std=c++11 ")

add_executable(PAT BinaryTreeTraverse.cpp )
