cmake_minimum_required(VERSION 3.24)

project(fbmath)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror -Wall")

add_library(fbmath INTERFACE)

target_include_directories(fbmath
        INTERFACE include)

target_include_directories(fbmath
        INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

set(fbmathtests
        vec2test
        ray2test
        boundingboxtest
        matrixtest
        circletest
        simdvec3buffertest
        spheretest
)

add_subdirectory(external/fbtt)
enable_testing()
foreach (test IN LISTS fbmathtests)

    add_executable(${test} tests/${test}.cpp)
    add_test(
            NAME "${test}"
            COMMAND ${test}
    )

    target_include_directories(${test}
            PRIVATE include
            PRIVATE external/fbtt/include)

    target_link_libraries(${test}
            PRIVATE fbtt
            PRIVATE fbmath)

endforeach ()