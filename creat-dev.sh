#! /bin/bash
chcp 65001
echo "生成一个开发用的VS工程目录"

mkdir build
cd build
conan install .. -s build_type=Debug -o build_test=True --build missing 
cmake .. -G "Unix Makefiles" -DXUEXUEJSON_BUILD_TESTS:BOOL="1" -DCMAKE_CONFIGURATION_TYPES:STRING="Debug"
make