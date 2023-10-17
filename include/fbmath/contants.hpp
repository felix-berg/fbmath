// Created by felix on 11/12/22, 9:35 PM.
#pragma once

#include <concepts>
namespace fb {
namespace math {
template <std::floating_point T = float>
constexpr T pi =
    3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811;

template <std::floating_point T = float>
constexpr T twoPi = T(2.0) * pi<T>;

template <std::floating_point T = float>
constexpr T halfPi = pi<T> / T(2.0);

template <std::floating_point T = float>
constexpr T quarterPi = pi<T> * T(0.25);
}
}