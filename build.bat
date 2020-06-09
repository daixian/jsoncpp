chcp 65001
REM windows平台编译项目
set CONAN_REVISIONS_ENABLED=1
set CONAN_ARCHIVE_PATH=%~dp0archive
conan create . daixian/stable -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release --build missing
REM conan create . daixian/stable -s compiler.version=16 -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release --build missing
REM conan upload xuexuejson/1.1.1@daixian/stable --all -r=xuexue
