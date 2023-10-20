// Created by felix on 10/18/23, 1:58 PM

#include <fbtt.hpp>
#include "fbmath/primitives/sphere.hpp"
#include <fbmath/intersection/sphere-ray-intersection.hpp>
#include <fbmath/ostream_interop.hpp>

int main()
{
    using namespace fb::math;
    using namespace fbtt;

    MultiTest st { "Test of sphere" };

    st.addTest("Construction of spheres", [] {
        Sphere s1 { 1, 2, 3, 4 };
        assertEquals(s1.c,
            V3i { 1, 2, 3 });
        assertEquals(s1.r, 4);

        Sphere s2 { 1.0, 42.0, 41.0, 30.0 };
        assertEquals(s2.c,
            V3d { 1.0, 42.0, 41.0 });
        assertEquals(s2.r, 30.0);

    });

    st.addTest("Sphere/ray intersection", [] {
        Sphere sphere { 2.59, -0.3, 3.4, 1.5 };
        Ray3<double> ray { { -0.3, 2.8, 1.0 }, { 0.3, -0.5, 0.4 } };

        const auto its = intersection(sphere, ray);
        assertTrue(its.has_value(), "No intersection!");

        V3d e1 { 2.21662, -1.39436, 4.35549 };
        V3d e2 { 1.23578, 0.240361, 3.04771 };
        assertApprox(its->first.x, e1.x);
        assertApprox(its->first.y, e1.y);
        assertApprox(its->first.z, e1.z);

        assertApprox(its->second.x, e2.x);
        assertApprox(its->second.y, e2.y);
        assertApprox(its->second.z, e2.z);
    });

    st.run();
    std::cout << st;
    return getErrorCode(st.getResults());
}