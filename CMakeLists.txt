cmake_minimum_required(VERSION 3.0)
project(strace_like)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_C_FLAGS -g)

add_subdirectory(src)
