cmake_minimum_required(VERSION 3.24)
project(tp10)

set(CMAKE_CXX_STANDARD 17)

add_executable(tp10 main.cpp IllegalArgumentException.cpp IllegalArgumentException.h Point.cpp Point.h NegativeDimensionException.cpp NegativeDimensionException.h InputFile.cpp InputFile.h Exception.cpp Exception.h)
