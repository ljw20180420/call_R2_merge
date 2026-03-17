cmake_minimum_required(VERSION 3.28.3)
project(fqtools)

add_executable(fqtools main.cpp)
set(CMAKE_BUILD_TYPE "Release")
target_compile_options(fqtools PRIVATE -O3 -std=c++20 -static)

install(TARGETS fqtools RUNTIME DESTINATION bin)
