cmake_minimum_required(VERSION 3.24)
project(construct)

set(CMAKE_CXX_STANDARD 17)

add_executable(construct main.cpp Perso.h Perso.cpp Weapon.cpp)
