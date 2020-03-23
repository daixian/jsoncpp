#!/usr/bin/env python3
# coding=utf-8
import os
import sys
import io
import platform
import subprocess

os.system("chcp 65001")
# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf8')


def system(command):
    retcode = os.system(command)
    if retcode != 0:
        raise Exception("Error while executing:\n\t %s" % command)


def get_git_tag() -> str:
    """得到当前git的tag文本"""
    # stream = os.popen('git tag -n10')
    # gitTag = stream.read()
    # return gitTag.strip()
    process = subprocess.Popen(['git', 'tag', '-n10'],
                               stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE, encoding="utf-8")
    stdout, stderr = process.communicate()
    return stdout.strip()


if __name__ == "__main__":
    print(sys.version)
    #删除原先安装的库,它会影响构建
    system('conan remove xuexuejson -f')

    params = " ".join(sys.argv[1:])
    gitTag = get_git_tag()
    print("当前git的tag是:" + gitTag)
    os.putenv('CUR_GIT_TAG', gitTag)
    sys.stdout.flush()

    pydir = os.path.split(os.path.realpath(__file__))[0]
    archivedir = pydir+os.sep+"temp"+os.sep+"archive"+os.sep+"xuexuejson"
    # 设置环境变量，CONAN_REVISIONS_ENABLED
    os.putenv('CONAN_REVISIONS_ENABLED', '1')
    # 设置环境变量，拷贝ARCHIVE的文件夹目录
    os.putenv('CONAN_ARCHIVE_PATH', archivedir)
    print('设置archivedir:', archivedir)
    print("当前平台是:"+platform.system())
    sys.stdout.flush()
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
