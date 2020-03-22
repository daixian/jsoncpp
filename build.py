#!/usr/bin/env python3
# coding=utf-8
import os
import sys
import platform


def system(command):
    retcode = os.system(command)
    if retcode != 0:
        raise Exception("Error while executing:\n\t %s" % command)


if __name__ == "__main__":
    params = " ".join(sys.argv[1:])
    if platform.system() == "Windows":
        print("当前平台是windows.")
        system('set CONAN_REVISIONS_ENABLED=1')
        system('conan create . daixian/stable -s compiler.version=15 -s compiler.runtime=MD \
        -s arch=x86_64 -s build_type=Release --build missing %s' % params)
    elif platform.system() == "Linux":
        print("当前平台是Linux.")
        # 使用gcc7
        system('export CC=/usr/bin/gcc-7')
        system('export CXX=/usr/bin/g++-7')
        system('export CONAN_REVISIONS_ENABLED=1')
        system('conan create . daixian/stable -s compiler.version=7.5 -s arch=x86_64 \
        -s build_type=Release --build missing')
    else:
        pass
