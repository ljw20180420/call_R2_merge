cmake_minimum_required(VERSION 3.28.3)
project(call_r2_merge)

add_executable(call_r2_merge main.cpp)
set(CMAKE_BUILD_TYPE "Release")
target_compile_options(call_r2_merge PRIVATE -O3 -std=c++20 -static)

install(TARGETS call_r2_merge RUNTIME DESTINATION bin)
