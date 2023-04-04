cmake_minimum_required(VERSION 3.21)
project(MyTest)

include(tool/common.cmake)
include(tool/fetch.cmake)


add_executable(Test main.cpp)       #添加源文件
add_subdirectory(benchmark)