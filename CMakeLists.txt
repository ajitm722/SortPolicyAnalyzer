cmake_minimum_required(VERSION 3.10)
project(ModernSortProject)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/sort_utils.cpp
)

# Executable target
add_executable(ModernSortProject ${SOURCES})

