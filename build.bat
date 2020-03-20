chcp 65001
REM windows平台编译项目
set CONAN_REVISIONS_ENABLED=1
conan create . daixian/stable -s compiler.version=15 -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release --build missing
conan create . daixian/stable -s compiler.version=16 -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release --build missing
conan upload xuexuejson/1.1.1@daixian/stable --all -r=xuexue
