# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Battleship VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the executable (or library)
file(GLOB SOURCES "src/*.cpp")
add_executable(Battleship ${SOURCES})