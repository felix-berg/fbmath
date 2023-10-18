// Created by felix on 11/12/22, 10:50 PM.
#include "fbmath/boundingbox.hpp"
#include <fbtt.hpp>

int main() {
    using namespace fbtt;
    using namespace fb::math;

    MultiTest bt { "Test of BoundingBox" };

    bt.addTest("Construction",
        []() {
            BoundingBox<long> bb1;
            assertEquals(bb1.br, Vec2<long>{0, 0});
            assertEquals(bb1.tl, Vec2<long>{0, 0});


            BoundingBox<long> bb2 { 2, 12, 4, 14 };
            assertEquals(bb2.tl, Vec2<long>{2, 12});
            assertEquals(bb2.br, Vec2<long>{4, 14});

            const V2i tl = { 53, 24 };
            const V2i br = { 1043, 4128 };
            BoundingBox bb3 { tl, br };
            assertEquals(bb3.tl, tl);
            assertEquals(bb3.br, br);
        }
    );

    bt.addTest("Contains",
        []() {
            BoundingBox<long> bb { -21378, 11382, -14832, 148902 };
            assertTrue(bb.contains({-21378, 11382}), "Not inclusive of tl");
            assertFalse(bb.contains({-14832, 148902}), "Not exclusive of br");

            BoundingBox<long> bb1 { 2, 12, 4, 14 };
            const V2d
                a = { 2.37, 12.64 },
                b = { 3.4, 13.22  },
                c = { 3.01, 14.68 },
                d = { 1.35, 13.38 },
                e = { 2.81, 11.13 },
                f = { 5.21, 12.74 };

            assertTrue(bb1.contains(a), "a failed");
            assertTrue(bb1.contains(b), "b failed");
            assertTrue(!bb1.contains(c), "c failed");
            assertTrue(!bb1.contains(d), "d failed");
            assertTrue(!bb1.contains(e), "e failed");
            assertTrue(!bb1.contains(f), "f failed");
        }
    );

    bt.addTest("Overlaps",
        []() {
            BoundingBox b1 = { 2, -6, 6, -2 };
            BoundingBox b2 = { 4.62, -3.28, 12.0, 6.0 };
            BoundingBox b3 = { 3.04, -9.45, 8.31, -4.94 };
            BoundingBox b4 = { 0, -14, 4, -11 };

            assertTrue(b1.overlapsWith(b2), "b2 failed");
            assertTrue(b1.overlapsWith(b3), "b3 failed");
            assertFalse(b1.overlapsWith(b4), "b4 failed");
        }
    );

    bt.run();
    std::cout << bt;

    return getErrorCode(bt.getResults());
}
