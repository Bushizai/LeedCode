cmake_minimum_required(VERSION 3.22)

set(DYNAMIC_LIBRARY_NAME LeedCode-11)

project(${DYNAMIC_LIBRARY_NAME})

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)

# file(GLOB SRC_LIST "${CMAKE_SOURCE_DIR}/src/11.cpp")

set(maxArea_src "${CMAKE_SOURCE_DIR}/Subdirectory/src/maxArea.cpp")

# 设置动态库输出路径
# LIBRARY_OUTPUT_PATH：默认存放库文件的路径，可以自定义
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/libs)

# 生成动态库
add_library(${DYNAMIC_LIBRARY_NAME} SHARED ${maxArea_src})

# 设置包含目录
target_include_directories(${DYNAMIC_LIBRARY_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# LIBRARY_OUTPUT_DIRECTORY：默认存放动态库的位置
# ARCHIVE_OUTPUT_DIRECTORY：默认存放静态库的位置
set_target_properties(${DYNAMIC_LIBRARY_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH})