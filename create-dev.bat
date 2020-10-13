chcp 65001
REM 生成一个开发用的VS工程目录

mkdir build
cd build

conan install ../test_package -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release --build missing
REM 后面使用cmake插件来配置就可以了

REM 如果不使用上面的cmake插件那么执行这个也行
REM cmake ../src -G "Visual Studio 15 Win64" -DXUEXUEJSON_BUILD_TESTS:BOOL="1" -DCMAKE_CONFIGURATION_TYPES:STRING="Debug;Release;RelWithDebInfo"