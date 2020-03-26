cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SUB_NAME "xuexuejson")

# set(SOURCE_LIST
#     main.cpp
# )
# 先自动添加算了
FILE(GLOB_RECURSE SOURCE_LIST "*.cpp" "*.h" "*.hpp" "*.c")

# 这个函数在VS工程里生成一个文件路径
function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        #这个表示在VS里划分一个组
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)

assign_source_group(${SOURCE_LIST})
message(STATUS "SOURCE_LIST = ${SOURCE_LIST}")

# Library definition
add_library(${SUB_NAME} INTERFACE)

# SET_TARGET_PROPERTIES（${SUB_NAME} PROPERTIES LINKER_LANGUAGE C11）
# find_package(Threads)

# if(WIN32)
#     add_custom_command(TARGET ${SUB_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory "${CONAN_BIN_DIRS_DLOG}" ${EXECUTABLE_OUTPUT_PATH}) #拷贝整个文件夹算了
# endif()

message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CONAN_LIBS = ${CONAN_LIBS}")

target_sources(${SUB_NAME} INTERFACE ${SOURCE_LIST})
target_include_directories(${SUB_NAME} INTERFACE ${CMAKE_SOURCE_DIR})
# target_link_libraries(${SUB_NAME} INTERFACE ${CONAN_LIBS} ${CMAKE_THREAD_LIBS_INIT})


# # 全都安装到根目录
# install(TARGETS ${SUB_NAME}
#        RUNTIME DESTINATION "./"
#        LIBRARY DESTINATION "./"
#        ARCHIVE DESTINATION "./"
# )
# 安装头文件
# install(FILES "dlog.h" DESTINATION "./")
# install(FILES "../UnitTest/DLog.cs" DESTINATION "./")

# Configuration
# set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
# set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
# set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
# set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
