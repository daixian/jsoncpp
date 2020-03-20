#! /bin/bash

echo "生成一个开发用的VS工程目录"

export CC=/usr/bin/gcc-7
export CXX=/usr/bin/g++-7

conan create . daixian/stable -s compiler.version=15 -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release --build missing
 
