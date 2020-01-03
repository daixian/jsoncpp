cmake_minimum_required(VERSION 3.1.0)

#增加这个wrapper工程让vscode的cmake插件可以工作
project(cmake_wrapper VERSION 1.0.0 LANGUAGES CXX)

message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

#从build目录里去得到conanbuildinfo.cmake
set(CONAN_BUILD_INFO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CONAN_BUILD_INFO_PATH})
conan_basic_setup()

include(CheckIncludeFile)

add_subdirectory("src")
