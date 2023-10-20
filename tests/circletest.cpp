// Created by felix on 11/13/22, 2:24 PM.
#include "fbmath/primitives/circle.hpp"
#include "fbmath/intersection/circle-ray-intersection.hpp"
#include <fbtt.hpp>

int main() {
    using namespace fbtt;
    using namespace fb::math;

    MultiTest ct { "Test of circle" };

    ct.addTest("Construction",
        []() {
            const Circle<long> cl;
            const Circle<float> cf { 1.0f, 1.5f, 42.0f };
            const V2d c = { 2.0234, 13.24 };
            const Circle<double> cd = { c, 50 };

            assertEquals(cl.c, V2l(0, 0));
            assertEquals(cl.r, 0.0f);
            assertEquals(cf.c, V2f(1.0f, 1.5f));
            assertEquals(cf.r, 42.0f);
            assertEquals(cd.c, c);

        }
    );

    ct.addTest("Intersection with ray",
        []() {
            const Circle c { 5, 6, 3 };
            const Ray<V2d> r { { 3.0, 1.0 }, { 2.01, 10.05 } };
            const auto opt = intersection(c, r);
            assertTrue(opt.has_value(), "Intersection not found");
        }
    );

    ct.run();
    std::cout << ct;
}