#!/usr/bin/env python3
# coding=utf-8
import os
import sys
import platform


def system(command):
    retcode = os.system(command)
    if retcode != 0:
        raise Exception("Error while executing:\n\t %s" % command)


def get_git_tag() -> str:
    """得到当前git的tag文本"""
    stream = os.popen('git tag -n10')
    gitTag = stream.read()
    return gitTag.strip()


if __name__ == "__main__":
    print(sys.version)
    params = " ".join(sys.argv[1:])
    gitTag = get_git_tag()
    print("当前git的tag是:" + gitTag)
    os.putenv('CUR_GIT_TAG', gitTag)

    pydir = os.path.split(os.path.realpath(__file__))[0]
    archivedir = pydir+os.sep+"temp"+os.sep+"archive"+os.sep+"xuexuejson"
    # 设置环境变量，CONAN_REVISIONS_ENABLED
    os.putenv('CONAN_REVISIONS_ENABLED', '1')
    # 设置环境变量，拷贝ARCHIVE的文件夹目录
    os.putenv('CONAN_ARCHIVE_PATH', archivedir)
    print("当前平台是:"+platform.system())
    if platform.system() == "Windows":
        cmd = 'conan create . daixian/stable -s compiler.version=15 -s compiler.runtime=MD \
-s arch=x86_64 -s build_type=Release --build missing %s' % params
        system(cmd)
    elif platform.system() == "Linux":
        # 使用gcc7
        os.environ['CC'] = '/usr/bin/gcc-7'
        os.environ['CXX'] = '/usr/bin/g++-7'
        system('conan create . daixian/stable -s compiler.version=7.5 -s arch=x86_64 \
        -s build_type=Release --build missing')
    else:
        pass
