cmake_minimum_required(VERSION 3.8)
include($ENV{cpp_lib_build_scripts_path}/cmake-module/setup.cmake)

set(ProjectName base)
project(${ProjectName})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

# 编译目标
add_library(${ProjectName})
target_import_src(${ProjectName})

if(has_thread)
	message(STATUS "此平台拥有线程")
	target_compile_definitions(${ProjectName} PUBLIC HAS_THREAD=1)
endif()

set(CMAKE_INSTALL_PREFIX ${cpp_lib_build_scripts_path}/${platform}/.libs/${ProjectName}/)