# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(TGSG VERSION 0.1)

configure_file(TGSGConfig.h.in TGSGConfig.h)

# Build for C++17
set(CMAKE_CXX_STANDARD 17)

add_executable(
    tgsg
    main.cpp
)
