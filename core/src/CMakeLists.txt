cmake_minimum_required(VERSION 3.9.1)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

add_library(Calculator STATIC "Calculator.cpp")