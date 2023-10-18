// Created by felix on 10/18/23, 12:27 PM
#pragma once

#include "number.hpp"
#include "vec3.hpp"

namespace fb { namespace math {
template <Number N>
struct Sphere {
    Vec3<N> c;
    N r;

    constexpr Sphere()
        : c { }, r { } { };

    constexpr Sphere(const Vec3<N>& _c, N _r)
        : c { _c }, r { _r } { };

    constexpr Sphere(N cx, N cy, N cz, N _r)
        : Sphere { Vec3<N>(cx, cy, cz), _r } { };
};
}
}