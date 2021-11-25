# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(TGSG VERSION 0.1)

configure_file(TGSGConfig.h.in TGSGConfig.h)

# Build for C++17
set(CMAKE_CXX_STANDARD 17)

configure_file(TGSGConfig.h.in TGSGConfig.h)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    tgsg
    main.cpp
)
target_link_libraries(
    tgsg
    gtest_main
)
#include(GoogleTest)
#gtest_discover_tests(tgsg)
