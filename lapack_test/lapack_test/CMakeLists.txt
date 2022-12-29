cmake_minimum_required(VERSION 3.5)

project(lapack_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(lapack_test main.cpp)
#include_directories("D:/Soft/lapackpp/include/lapackpp")

#include_directories("D:/Tmp/probs/c_tests/test_make/lib/include")
#add_subdirectory("D:/Soft/LINAL/BLAS/CLBlast")
message("clblast inslall = ${clblast_DIR}")

find_package(clblast REQUIRED)
target_link_libraries(lapack_test clblast)





