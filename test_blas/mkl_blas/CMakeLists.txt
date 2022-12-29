cmake_minimum_required(VERSION 3.5)

project(mkl_blas_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mkl_blas_test main.cpp)


#list(APPEND CMAKE_MODULE_PATH ${OpenBLAS_DIR})

message("CMAKE_MODULE_PATH :  ${CMAKE_MODULE_PATH}")

set(BLA_VENDOR CONFIG OpenBLAS)
find_package(OpenBLAS REQUIRED)
message("openblas : ${OpenBLAS_FOUND}")
message("openblas : ${BLAS_FOUND}")
message("openblas libs : ${OpenBLAS_LIBRARIES}")
message("openblas include : ${OpenBLAS_INCLUDE_DIRS}")
#add_executable(mkl_blas_test main.cpp)
#include_directories(${OpenBLAS_INCLUDE})
include_directories(mkl_blas_test ${OpenBLAS_INCLUDE_DIRS})

target_link_libraries(mkl_blas_test ${OpenBLAS_LIBRARIES})

