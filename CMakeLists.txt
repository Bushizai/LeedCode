cmake_minimum_required(VERSION 3.17)

project(LeedCode-x)

set(CMAKE_CXX_STANDARD 17)

set(SUB_CMAKELISTS_TXT_DIR ${CMAKE_SOURCE_DIR}/Subdirectory)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/Subdirectory/src)

add_subdirectory(${SUB_CMAKELISTS_TXT_DIR})

# 添加动态库文件
set(DYNAMIC_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${DYNAMIC_LIBRARY_DIR})

# 设置leecode题目的ID号，方便记录
set(ID 11)
add_executable(leedcode_${ID} ${SRC_DIR}/main.cpp)
target_link_libraries(leedcode_${ID} LeedCode-11)

# g++ -c maxArea.cpp -o maxArea.o
# g++ 11.cpp maxArea.o -o 11