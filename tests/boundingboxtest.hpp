// Created by felix on 11/12/22, 10:50 PM.
#pragma once

#include "2D/boundingbox.hpp"
#include <fbtt.hpp>

namespace fbmath {
void boundingboxtest() {
    using namespace fbtt;

    MultiTest bt { "Test of BoundingBox" };

    bt.add_test("Construction",
        []() {
            BoundingBox<long> bb1;
            assert_equals(bb1.br, Vec2<long>{0, 0});
            assert_equals(bb1.tl, Vec2<long>{0, 0});


            BoundingBox<long> bb2 { 2, 12, 4, 14 };
            assert_equals(bb2.tl, Vec2<long>{2, 12});
            assert_equals(bb2.br, Vec2<long>{4, 14});

            const V2i tl = { 53, 24 };
            const V2i br = { 1043, 4128 };
            BoundingBox bb3 { tl, br };
            assert_equals(bb3.tl, tl);
            assert_equals(bb3.br, br);
        }
    );

    bt.add_test("Contains",
        []() {
            BoundingBox<long> bb { -21378, 11382, -14832, 148902 };
            assert_true(bb.contains({-21378, 11382}), "Not inclusive of tl");
            assert_false(bb.contains({-14832, 148902}), "Not exclusive of br");

            BoundingBox<long> bb1 { 2, 12, 4, 14 };
            const V2d
                a = { 2.37, 12.64 },
                b = { 3.4, 13.22  },
                c = { 3.01, 14.68 },
                d = { 1.35, 13.38 },
                e = { 2.81, 11.13 },
                f = { 5.21, 12.74 };

            assert_true(bb1.contains(a), "a failed");
            assert_true(bb1.contains(b), "b failed");
            assert_true(!bb1.contains(c), "c failed");
            assert_true(!bb1.contains(d), "d failed");
            assert_true(!bb1.contains(e), "e failed");
            assert_true(!bb1.contains(f), "f failed");
        }
    );

    bt.add_test("Overlaps",
        []() {
            BoundingBox b1 = { 2, -6, 6, -2 };
            BoundingBox b2 = { 4.62, -3.28, 12.0, 6.0 };
            BoundingBox b3 = { 3.04, -9.45, 8.31, -4.94 };
            BoundingBox b4 = { 0, -14, 4, -11 };

            assert_true(b1.overlapsWith(b2), "b2 failed");
            assert_true(b1.overlapsWith(b3), "b3 failed");
            assert_false(b1.overlapsWith(b4), "b4 failed");
        }
    );

    bt.run();
    std::cout << bt;
}
}
