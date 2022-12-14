cmake_minimum_required(VERSION 3.24)
project(image)

set(CMAKE_CXX_STANDARD 17)

add_executable(image main.cpp PGM.h PGM.cpp PPM.cpp)
