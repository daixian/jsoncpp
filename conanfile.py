#!/usr/bin/env python3
# coding=utf-8
import os
import sys
import io
import shutil
from conans import ConanFile, CMake, tools


# os.system("chcp 65001")
# 注意这里不能用下面那一句去设置,否则conan库会报错的
# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf8')

class xuexuejsonConan(ConanFile):
    name = "xuexuejson"
    version = "1.3.3"
    license = "GLWTPL (Good Luck With That Public License)"
    author = "daixian<amano_tooko@qq.com>"
    url = "https://github.com/daixian/jsoncpp"
    description = "c++，基于rapidjson的json封装，纯头文件，高性能。"
    topics = ("json", "rapidjson", "daixian")
    settings = "os"
    options = None
    default_options = None
    generators = "cmake"
    exports_sources = "src/*"

    def requirements(self):
        # https://docs.conan.io/en/latest/mastering/conditional.html
        # 标准的写法是requires()
        self.requires("rapidjson/[>=1.1.0]")

    def _configure_cmake(self):
        """转换python的设置到CMake"""
        cmake = CMake(self)
        # cmake.definitions["DNET_BUILD_SHARED"] = self.options.shared
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.configure(source_folder="src")
        cmake.build()
        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.hpp", dst="include", src="src")
        # self.copy("*.lib", dst="lib", keep_path=False)
        # self.copy("*.dll", dst="bin", keep_path=False)
        # self.copy("*.dylib*", dst="lib", keep_path=False)
        # self.copy("*.so", dst="lib", keep_path=False)
        # self.copy("*.a", dst="lib", keep_path=False)
        self.copy_archive()

    def copy_archive(self):
        """把安装文件拷贝到当前源文件目录来,方便在CI中上传"""
        dest = os.environ.get("CONAN_ARCHIVE_PATH")
        print("copy_archive():environ CONAN_ARCHIVE_PATH=" + dest)
        dest = dest + os.sep + str(self.name)
        if os.path.exists(dest):
            shutil.rmtree(dest)
        if not dest is None:
            self.copy("*.h", dst=dest + os.sep + "include", src="src")
            self.copy("*.hpp", dst=dest + os.sep + "include", src="src")
        else:
            print("copy_archive():environ CONAN_ARCHIVE_PATH=None，can not archive copy!")

    def package_info(self):
        self.info.header_only()
        # self.cpp_info.libs = ["jsoncpp"]
        if self.settings.os == "Windows":
            # 防止宏定义冲突
            self.cpp_info.defines.append("NOMINMAX")

    def imports(self):
        """这个函数的相关文档:
        * 1. Before running build() it will execute imports() in the build folder, copying dependencies artifacts
        * 2. Run the build() method, which could use such imported binaries.
        * 3. Remove the copied (imported) artifacts after build() is finished.
        https://docs.conan.io/en/latest/reference/conanfile/methods.html#imports"""
        self.copy("LICENSE", dst="licenses", folder=True, ignore_case=True)

    # def deploy(self):
        # self.copy("*.h", dst="archive/include", src="src")
        # self.copy("*.hpp", dst="archive/include", src="src")
        # self.copy("*.exe")  # copy from current package
        # self.copy_deps("*.dll") # copy from dependencies
