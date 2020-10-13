#! /bin/bash
# chcp 65001
# echo "生成一个开发用的xCode工程目录,注意如果xCode升级了之后,那么cmake工具的版本也需要升级."

mkdir build
cd build
conan install ../test_package -s build_type=Release --build missing
# make