// Created by felix on 11/13/22, 2:24 PM.
#pragma once

#include <2D/circle.hpp>
#include <2D/unfinished_circle-ray-intersection.hpp>
#include <fbtt.hpp>

namespace fbmath {
void circleTest() {
    using namespace fbtt;

    MultiTest ct { "Test of circle" };

    ct.add_test("Construction",
        []() {
            const Circle<long, float> clf;
            const Circle<float, float> cff { 1.0f, 1.5f, 42.0f };
            const V2d c = { 2.0234, 13.24 };
            const Circle<double> cdd = { c, 50 };

            assert_equals(clf.c, V2l(0, 0));
            assert_equals(clf.r, 0.0f);
            assert_equals(cff.c, V2f(1.0f, 1.5f));
            assert_equals(cff.r, 42.0f);
            assert_equals(cdd.c, c);

        }
    );

//    ct.add_test("Intersection with ray",
//        []() {
//            const Circle c { 5, 6, 3 };
//            const Ray r { 3.0, 1.0, 1.0, 2.0 };
//            const auto opt = intersection(r, c);
//            assert_true(opt.has_value(), "Intersection not found");
//            std::cout << "Intersections: " << opt->first / 2 << ", " << opt->second / 2 << '\n';
//        }
//    );

    ct.run();
    std::cout << ct;
}
}