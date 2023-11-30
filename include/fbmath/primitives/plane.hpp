// Created by felix on 10/20/23, 4:47 PM
#pragma once

#include "fbmath/primitives/primitive-predeclaration.hpp"

namespace fb{ namespace math {

template <typename N>
struct Plane {
    Vec3<N> normal;
    N d;

    constexpr Plane() = default;
    constexpr Plane(const Vec3<N>& normal, float d_)
        : normal { normal }, d { d_ } { }
    constexpr Plane(const Vec3<N>& normal, const Vec3<N>& point)
        noexcept : Plane { normal, -dotProduct(normal, point) } { }
};

}}