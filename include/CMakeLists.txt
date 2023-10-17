cmake_minimum_required(VERSION 3.24)
project(fbmath)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror -Wall")

add_library(fbmath INTERFACE
        fbmath/matrixview_old.hpp
        fbmath/matrix_old.hpp
        fbmath/matrix.hpp)

target_include_directories(fbmath
        INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)