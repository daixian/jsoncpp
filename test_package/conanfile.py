import os

from conans import ConanFile, CMake, tools


class xuexuejsonTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def requirements(self):
        self.requires("eigen/3.3.7")   
        self.requires("opencv/4.2.0@daixian/stable")
        self.requires("rapidjson/1.1.0")

    def build_requirements(self):
        self.build_requires("gtest/1.8.1@bincrafters/stable")
        self.build_requires("boost/1.71.0")
        self.build_requires("poco/1.9.4")      
        

    def build(self):
        cmake = CMake(self)
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is
        # in "test_package"
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

    def test(self):
        if not tools.cross_building(self.settings):
            os.chdir("bin")
            self.run(".%stest" % os.sep)
