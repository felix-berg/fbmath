// Created by felix on 11/12/22, 6:39 PM.
#pragma once

#include "2D/vec2.hpp"
#include "trigonometry.hpp"
#include <fbtt.hpp>
#include <iostream>
#include <limits>
#include <ostream_interop.hpp>

namespace fbmath {
void vec2test()
{
    using namespace fbtt;

    /* Construction */
    MultiTest vt { "Test of vec2" };

    vt.add_test("Construction",
        []() {
            V2i v1 [[maybe_unused]];
            V2i v2(1, 2);

            char c = 5;
            V2i v3(c, c);

            static_assert(MorePreciseThan<long, int>);
            static_assert(!MorePreciseThan<int, long>);
            static_assert(NonNarrowingConvertibleTo<int, long>);
            static_assert(!NonNarrowingConvertibleTo<long, int>);

            long x = std::numeric_limits<long>::max(), y = 50;
            Vec2<float> vf = { x, y }; /* integral -> fp allowed */
            Vec2<double> vd = vf; /* allowed */

            /* Vec2<float> vf2 = vd <- doesn't compile */
            Vec2<float> vf2 [[maybe_unused]] = vd.convertTo<float>();
        }
    );

    vt.add_test("Setting",
        []() {
            V2f vf(142.0f, 414.0f);
            assert_equals(vf, V2f(142.0f, 414.0f));
            vf = {143.0f, 415.0f};
            assert_equals(vf, V2f(143.0f, 415.0f));
        }
    );

    vt.add_test("Equality",
        []() {
            V2i v { 5, 6 };
            assert_equals(v, v);
            V2i u { 5, 7 };
            assert_noteq(v, u);
            u = { 6, 6 };
            assert_noteq(v, u);
            u = { 6, 7 };
            assert_noteq(v, u);

            V2f vf { 5.01323f, 561.0123f };
            V2d vd { vf };

            assert_true(vf == vd);
            vd = { -23.0, -1323 };
            assert_true(vf != vd);
        }
    );

    vt.add_test("Dot product",
        []() {
            V2i v { 4, 5 };
            V2i u { 7, 8 };

            assert_equals(dotProduct(v, u), 28 + 40);
        }
    );

    vt.add_test("Absolute angle",
        []() {
            constexpr double margin = 0.01f;
            V2d v { 5.38, 3.38 };
            assert_approx(degrees(v.angle()), 32.14, "Bruh", margin);

            V2d u { 19.51, -6.4 };
            assert_approx(degrees(u.angle()), 341.84, "Bruh", margin);
        }
    );

    vt.add_test("Angle between",
        []() {
            /* using geogebra */
            V2d v { 3.84, 3.3 };
            V2d u { -1.88, 5.16 };
            assert_approx(angleBetween<float>(v, u), 1.2102);

            v = { -2.8, 2.66 };
            u = { -1.78, -4.88 };
            assert_approx(angleBetween<double>(v, u), 1.9808);
        }
    );

    vt.add_test("Setting angles",
        []() {
            V2d v { 1.0, 1.0 };
            assert_approx(degrees(v.angle()), 45.0);

            v.setAngle(radians(65.0));
            assert_approx(degrees(v.angle()), 65.0);

            v.setAngle(radians(140.0));
            assert_approx(degrees(v.angle()), 140.0);
        }
    );


    vt.run();
    std::cout << vt;
}
}
