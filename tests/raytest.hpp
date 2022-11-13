// Created by felix on 11/13/22, 12:36 AM.
#pragma once

#include <fbtt.hpp>
#include <2D/ray.hpp>

namespace fbmath {

void raytest()
{
    using namespace fbtt;
    MultiTest rt { "Test of ray" };

    rt.add_test("Construction",
        []() {
            Ray<double> r1;
            Ray r2 { 2.04, 1342.0, 1.0, 1.0 };
            Ray<long> r3 { {132, 13}, {0, 132} };

            assert_equals(r1.org, V2d{});
            assert_equals(r1.dir, V2d{});
            assert_equals(r2.org, V2d{2.04, 1342.0});
            assert_equals(r2.dir, V2d{1.0, 1.0});
            assert_equals(r3.org, V2l{132, 13});
            assert_equals(r3.dir, V2l{0, 132});
        }
    );

    rt.add_test("Intersection",
        []() {
            Ray r1 { 0.0, 0.0, 1.0, 1.0 };
            Ray r2 { 6.0, 1.0, 0.1, 0.82 };

            const std::optional<V2d> opt = intersection(r1, r2);
            assert_equals(V2i(opt.value()), V2i{6, 6}); /* its dumb ik */
        }
    );
    

    rt.run();
    std::cout << rt;
}

} // namespace fbmath