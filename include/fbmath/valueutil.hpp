// Created by felix on 10/19/23, 11:39 AM
#pragma once

#include <fbmath/number.hpp>

namespace fb { namespace math {

template <Number N>
N clamp(N value, N min, N max) noexcept
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
}}