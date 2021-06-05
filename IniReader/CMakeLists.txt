cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_library(ini_reader src/ini_reader.cpp)
target_include_directories(ini_reader PUBLIC include/)