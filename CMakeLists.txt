cmake_minimum_required(VERSION 3.1.0)

#增加这个wrapper工程让vscode的cmake插件可以工作
project(xuexuejson_wrapper VERSION 1.0.0 LANGUAGES CXX)

message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

#从build目录里去得到conanbuildinfo.cmake
set(CONAN_BUILD_INFO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CONAN_BUILD_INFO_PATH})
conan_basic_setup()

include(CheckIncludeFile)


# 现在使用了conan库,这里并不需要了，这里是为了方便创建一个可以link的调试工程
if(WIN32)
#   设置编译选项为MT https://stackoverflow.com/questions/14172856/compile-with-mt-instead-of-md-using-cmake
#     set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
#   为了调试版本来设置一下
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
endif()

# 防止vs工程install报错
# 修改一些默认值 Use this snippet *after* PROJECT(xxx):
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install CACHE PATH "Install directory" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

#设置文件输出的目录
message(STATUS "总工程的CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
add_subdirectory("src")
add_subdirectory("test_package")
