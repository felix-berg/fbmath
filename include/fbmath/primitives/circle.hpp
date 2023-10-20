// Created by felix on 11/13/22, 2:11 PM.
#pragma once
#include "fbmath/number.hpp"
#include "fbmath/primitives/vec2.hpp"

namespace fb {
namespace math {
template <Number N>
struct Circle {
    Vec2<N> c;
    N r;

    constexpr Circle()
        :c { }, r { } { };

    constexpr Circle(const Vec2<N>& _c, N _r)
        :c { _c }, r { _r } { };

    constexpr Circle(N cx, N cy, N _r)
        :Circle(Vec2<N>(cx, cy), _r) { };
};


} // fbmath
}