//#include <iostream>

#include "tests/vec2test.hpp"
#include "tests/boundingboxtest.hpp"
#include "tests/raytest.hpp"
#include "tests/circletest.hpp"

using namespace fbmath;

int main(int argc, char ** argv)
{
    vec2Test();
    boundingboxtest();
    rayTest();
    circleTest();

}
