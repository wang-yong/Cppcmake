cmake_minimum_required(VERSION 3.21)
project(Cppcmake)

include(tool/common.cmake)
include(tool/fetch.cmake)


add_executable(src main.cpp)       #添加源文件
add_subdirectory(benchmark)