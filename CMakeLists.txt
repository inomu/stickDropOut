cmake_minimum_required(VERSION 3.7)
project(StickDropOut)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp StickDropOut.cpp StickDropOut.h)
add_executable(StickDropOut ${SOURCE_FILES})