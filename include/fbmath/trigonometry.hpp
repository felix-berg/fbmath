// Created by felix on 11/12/22, 10:01 PM.
#pragma once

#include <fbmath/number.hpp>
#include <fbmath/contants.hpp>

namespace fb {
namespace math {
template <std::floating_point F = double>
constexpr F radians(F deg) noexcept
{
    return (deg * twoPi<F>) / F(360.0);
}

template <std::floating_point F = double>
constexpr F degrees(F rad) noexcept
{
    return (rad * F(360.0)) / twoPi<F>;
}
} // namespace fbmath
}