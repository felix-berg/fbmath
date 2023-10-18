// Created by felix on 11/12/22, 11:35 PM.
#pragma once

#include <fbmath/vec2.hpp>
#include <fbmath/vec3.hpp>
#include <optional>

namespace fb { namespace math {
template <typename Vector>
struct Ray {
    Vector org, dir;

    constexpr Ray() = default;

    constexpr Ray(const Vector& _org, const Vector& _dir)
        :org { _org }, dir { _dir } { };

    template <std::floating_point ParamType = double>
    constexpr Vector at(ParamType param) const noexcept
    {
        return org + dir * param;
    }
};

template <Number N>
using Ray2 = Ray<Vec2<N>>;

template <Number N>
using Ray3 = Ray<Vec3<N>>;

}
}; // namespace