cmake_minimum_required(VERSION 3.24)

project(fbmathTests)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror -Wall")

add_subdirectory(include)
add_subdirectory(external/fbtt)
include_directories(
    include
    external/fbtt/include)
link_libraries(fbmath fbtt)

enable_testing()

add_executable(vec2test tests/vec2test.cpp)
add_test(
    NAME "2D Vector"
    COMMAND vec2test
)

add_executable(raytest tests/raytest.cpp)
add_test(
        NAME "Ray"
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