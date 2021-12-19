cmake_minimum_required(VERSION 3.20)
project(smplog)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/logger.cpp)

add_executable(smplog ${SOURCE_FILES})
