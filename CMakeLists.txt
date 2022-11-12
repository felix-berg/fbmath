cmake_minimum_required(VERSION 3.24)
project(fbmath)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "-Werror -Wall")

add_executable(fbmath main.cpp)

target_include_directories(fbmath
        PUBLIC include)

target_link_directories(fbmath
        PUBLIC src)