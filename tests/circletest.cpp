// Created by felix on 11/13/22, 2:24 PM.
#include <fbmath/2D/circle.hpp>
#include <fbmath/2D/circle-ray-intersection.hpp>
#include <fbtt.hpp>

int main() {
    using namespace fbtt;
    using namespace fb::math;

    MultiTest ct { "Test of circle" };

    ct.addTest("Construction",
        []() {
            const Circle<long, float> clf;
            const Circle<float, float> cff { 1.0f, 1.5f, 42.0f };
            const V2d c = { 2.0234, 13.24 };
            const Circle<double> cdd = { c, 50 };

            assertEquals(clf.c, V2l(0, 0));
            assertEquals(clf.r, 0.0f);
            assertEquals(cff.c, V2f(1.0f, 1.5f));
            assertEquals(cff.r, 42.0f);
            assertEquals(cdd.c, c);

        }
    );

    ct.addTest("Intersection with ray",
        []() {
            const Circle c { 5, 6, 3 };
            const Ray r { 3.0, 1.0, 2.01, 10.05 };
            const auto opt = intersection(r, c);
            assertTrue(opt.has_value(), "Intersection not found");
        }
    );

    ct.run();
    std::cout << ct;
}