cmake_minimum_required(VERSION 3.24)

project(fbmath)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror -Wall")

add_subdirectory(external/fbtt)

include_directories(
    include
    external/fbtt/include)

link_libraries(fbmath fbtt)

add_library(fbmath INTERFACE)

target_include_directories(fbmath
        INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

enable_testing()

add_executable(vec2test tests/vec2test.cpp)
add_test(
    NAME "2D Vector"
    COMMAND vec2test
)

add_executable(raytest tests/ray2test.cpp)
add_test(
        NAME "2D Ray"
        COMMAND raytest
)

add_executable(circletest tests/circletest.cpp)
add_test(
        NAME "Circle"
        COMMAND circletest
)

add_executable(boundingboxtest tests/boundingboxtest.cpp)
add_test(
        NAME "Bounding Box"
        COMMAND boundingboxtest
)
add_executable(matrixtest tests/matrixtest.cpp)
add_test(
        NAME "Matrix"
        COMMAND matrixtest
)

add_executable(spheretest tests/spheretest.cpp)
add_test(
        NAME "Sphere"
        COMMAND spheretest
)