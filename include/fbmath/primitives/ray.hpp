// Created by felix on 11/12/22, 11:35 PM.
#pragma once

#include <optional>
#include "fbmath/primitives/primitive-predeclaration.hpp"
#include "fbmath/primitives/vec2.hpp"
#include "fbmath/primitives/vec3.hpp"

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

using Ray3i = Ray<V3i>;
using Ray3f = Ray<V3f>;
using Ray3d = Ray<V3d>;

template <Number N>
using Ray3 = Ray<Vec3<N>>;

using Ray3i = Ray<V3i>;
using Ray3f = Ray<V3f>;
using Ray3d = Ray<V3d>;
}
}; // namespace