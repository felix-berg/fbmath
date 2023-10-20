// Created by felix on 11/12/22, 6:39 PM.
#include "fbmath/primitives/vec2.hpp"
#include <fbmath/trigonometry.hpp>
#include <fbtt.hpp>
#include <iostream>
#include <limits>
#include <fbmath/ostream_interop.hpp>


int main(int argc, char** argv)
{
    using namespace fb::math;
    using namespace fbtt;

    /* Construction */
    MultiTest vt { "Test of vec2" };

    vt.addTest("Construction/conversion",
        []() {
            V2i v1 [[maybe_unused]];
            V2i v2(1, 2);

            char c = 5;
            V2i v3(c, c);

            static_assert(MorePreciseThan<long, int>);
            static_assert(!MorePreciseThan<int, long>);
            static_assert(NonNarrowingConvertibleTo<int, long>);
            static_assert(!NonNarrowingConvertibleTo<long, int>);

            static_assert(MorePreciseThan<float, int>);
            static_assert(NonNarrowingConvertibleTo<int, float>);
            static_assert(!MorePreciseThan<int, float>);
            static_assert(!NonNarrowingConvertibleTo<double, long>);

            long x = std::numeric_limits<long>::max(), y = 50;
            Vec2<float> vf = { x, y }; /* integral -> fp allowed */
            Vec2<double> vd = vf; /* allowed */

//            Vec2<float> vf2 = vd; // <- doesn't compile
            Vec2<float> vf3 [[maybe_unused]] = Vec2<float>::from(vd);
        }
    );

    vt.addTest("Setting",
        []() {
            V2f vf(142.0f, 414.0f);
            assertEquals(vf, V2f(142.0f, 414.0f));
            vf = {143.0f, 415.0f};
            assertEquals(vf, V2f(143.0f, 415.0f));
        }
    );

    vt.addTest("Equality",
        []() {
            V2i v { 5, 6 };
            assertEquals(v, v);
            V2i u { 5, 7 };
            assertNeq(v, u);
            u = { 6, 6 };
            assertNeq(v, u);
            u = { 6, 7 };
            assertNeq(v, u);

            V2f vf { 5.01323f, 561.0123f };
            V2d vd { vf };

            assertTrue(vf == vd);
            vd = { -23.0, -1323 };
            assertTrue(vf != vd);
        }
    );

    vt.addTest("Arithmetic",
        []() {
            V2f a, b, c;

            a = { 1.5f, 2 };
            b = { 3, 4.3f };
            c = a + b;
            assertEquals(c, V2f{4.5f, 6.3f});

            c = a * 4;
            assertEquals(c, V2f{1.5f * 4, 2.0f * 4});

            c = b / 3;
            assertEquals(c, V2f{1, 4.3f/3.0f});

            c *= 3;
            assertEquals(c, V2f{3.0f, 4.3f});

            c /= 4;
            assertEquals(c, V2f{3.0f/4.0f, 4.3f/4.0f});

            a += b;
            assertEquals(a, V2f{4.5f, 6.3f});
        }
    );

    vt.addTest("Dot product",
        []() {
            V2i v { 4, 5 };
            V2i u { 7, 8 };

            assertEquals(dotProduct(v, u), 28 + 40);
        }
    );

    vt.addTest("Absolute angle",
        []() {
            constexpr double margin = 0.01f;
            V2d v { 5.38, 3.38 };
            assertApprox(degrees(v.angle()), 32.14, "Bruh", margin);

            V2d u { 19.51, -6.4 };
            assertApprox(degrees(u.angle()), 341.84, "Bruh", margin);
        }
    );

    vt.addTest("Angle between",
        []() {
            /* using geogebra */
            V2d v { 3.84, 3.3 };
            V2d u { -1.88, 5.16 };
            assertApprox(angleBetween<float>(v, u), 1.2102);

            v = { -2.8, 2.66 };
            u = { -1.78, -4.88 };
            assertApprox(angleBetween<double>(v, u), 1.9808);
        }
    );

    vt.addTest("Setting angles",
        []() {
            V2d v { 1.0, 1.0 };
            assertApprox(degrees(v.angle()), 45.0);

            v.setAngle(radians(65.0));
            assertApprox(degrees(v.angle()), 65.0);

            v.setAngle(radians(140.0));
            assertApprox(degrees(v.angle()), 140.0);
        }
    );

    vt.run();
    std::cout << vt;

    return getErrorCode(vt.getResults());
}