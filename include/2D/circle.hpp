// Created by felix on 11/13/22, 2:11 PM.
#pragma once
#include <2D/ray.hpp>
namespace fbmath {
template <Number VecN, Number Radius = VecN>
struct Circle {
    Vec2<VecN> c;
    Radius r;

    constexpr Circle() : c {}, r {} { };
    constexpr Circle(const Vec2<VecN>& _c, Radius _r)
        : c { _c }, r { _r } { };
    constexpr Circle(VecN cx, VecN cy, Radius _r)
        : Circle(Vec2<VecN>(cx, cy), _r) { };
};


} // fbmath
