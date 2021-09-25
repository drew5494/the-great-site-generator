# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(the-great-site-generatpr)

# Build for C++17
set(CMAKE_CXX_STANDARD 17)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_library(Main main.cpp)
