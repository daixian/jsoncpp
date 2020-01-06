# coding: utf-8
from conans import ConanFile, CMake, tools

import os
import sys
import io
# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='gbk')

os.system("chcp 65001")


class xuexuejsonConan(ConanFile):
    name = "xuexuejson"
    version = "1.0.0"
    license = "<Put the package license here>"
    author = "daixian<amano_tooko@qq.com>"
    url = "https://github.com/daixian/jsoncpp"
    description = "c++的json,纯头文件"
    topics = ("json", "daixian")
    settings = "os", "compiler", "build_type", "arch"
    options = {"build_test": [True, False]}
    default_options = {"build_test": True}
    generators = "cmake"
    exports_sources = "src/*"

    def requirements(self):
        self.requires.add("rapidjson/1.1.0")

    def build_requirements(self):
        self.build_requires.add("gtest/1.8.1@bincrafters/stable")
        self.build_requires.add("boost/1.71.0")
        self.build_requires.add("poco/1.9.4")
        self.build_requires.add("eigen/3.3.7")
        self.build_requires.add("opencv/3.4.5@daixian/stable")

    def _configure_cmake(self):
        '''
        转换python的设置到CMake
        '''
        cmake = CMake(self)
        # cmake.definitions["DNET_BUILD_SHARED"] = self.options.shared
        cmake.definitions["XUEXUEJSON_BUILD_TESTS"] = self.options.build_test
        return cmake

    def build(self):
        print("进入了build...")
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

    def package_info(self):
        self.info.header_only()
        # self.cpp_info.libs = ["jsoncpp"]
