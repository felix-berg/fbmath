// Created by felix on 11/13/22, 12:36 AM.
#include <fbtt.hpp>
#include "fbmath/primitives/vec2.hpp"
#include "fbmath/primitives/ray.hpp"

int main(int argc, char** argv)
{
    using namespace fb::math;
    using namespace fbtt;
    MultiTest rt { "Test of ray" };

    rt.addTest("Construction",
        []() {
            Ray2<double> r1;
            Ray2<double> r2 { { 2.04, 1342.0 }, { 1.0, 1.0 } };
            Ray2<long> r3 { {132, 13}, {0, 132} };

            assertEquals(r1.org, V2d{});
            assertEquals(r1.dir, V2d{});
            assertEquals(r2.org, V2d{2.04, 1342.0});
            assertEquals(r2.dir, V2d{1.0, 1.0});
            assertEquals(r3.org, V2l{132, 13});
            assertEquals(r3.dir, V2l{0, 132});
        }
    );


    rt.run();
    std::cout << rt;

    return getErrorCode(rt.getResults());
}