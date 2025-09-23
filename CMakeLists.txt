cmake_minimum_required(VERSION 3.20)
project(LsmStorageEngine VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Debug/Release builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -O0)
    message(STATUS "Building in Debug mode")
else()
    add_compile_options(-O3)
    message(STATUS "Building in Release mode")
endif()

# Add source files (we'll create these next)
add_executable(lsm_demo
    src/main.cpp
)

target_include_directories(lsm_demo 
    PRIVATE include
)

# Enable testing
enable_testing()

message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")