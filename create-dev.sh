#!/bin/bash

echo "生成一个开发用的VS工程目录"

export CC=/usr/bin/gcc-7
export CXX=/usr/bin/g++-7

# 这个调试是基于cmake插件的,conan install命令用于在build文件夹下生成一个conanbuildinfo.cmake文件。
# 之后在launch.json的配置中,不需要启动构建了,去掉"preLaunchTask": "g++ build active file"这一行,直接调试即可。
mkdir build
cd build
conan install ../test_package -s compiler.version=7.5 -s build_type=Release --build missing 
# cmake .. -G "Unix Makefiles" -DXUEXUEJSON_BUILD_TESTS:BOOL="1" -DCMAKE_CONFIGURATION_TYPES:STRING="Debug"
# make