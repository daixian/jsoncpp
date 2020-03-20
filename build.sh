#!/bin/bash

echo "生成一个开发用的VS工程目录"

export CC=/usr/bin/gcc-7
export CXX=/usr/bin/g++-7

export CONAN_REVISIONS_ENABLED=1

conan create . daixian/stable -s compiler.version=7.5 -s arch=x86_64 -s build_type=Release --build missing
 
