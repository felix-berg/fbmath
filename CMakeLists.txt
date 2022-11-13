cmake_minimum_required(VERSION 3.24)
project(fbmath)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "-Werror -Wall")

# update modules (git submodule update --init --recursive)
find_package(Git QUIET)
IF (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if (GIT_SUBMODULE)
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update failed")
        endif()
    endif()
endif()

add_executable(fbmath main.cpp)

target_include_directories(fbmath
        PUBLIC include)

target_link_directories(fbmath
        PUBLIC src)