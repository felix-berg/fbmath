// Created by felix on 11/13/22, 2:24 PM.
#pragma once

#include "fbmath/ray.hpp"
#include "fbmath/circle.hpp"
#include "fbmath/ostream_interop.hpp"

#include <cassert>

namespace fb {
namespace math {

template <Number N>
using CircleRayIntersection = std::optional<std::pair<Vec2<N>, Vec2<N>>>;

template <Number C, Number R,
    std::floating_point ResultType = MorePreciseType<C, R>>
constexpr CircleRayIntersection<ResultType> intersection(
    const Circle<C>& circle, const Ray<Vec2<R>>& ray)
{
    using S = ResultType;
    using VS = Vec2<S>;

    const VS org = static_cast<VS>(ray.org);
    const VS oc = org - static_cast<VS>(circle.c);
    const VS dir = static_cast<VS>(ray.dir);
    const S rsq = static_cast<S>(circle.r) * static_cast<S>(circle.r);

    const S a = dir.sizeSquared();
    const S b = S{2} * (dotProduct(dir, oc));
    const S c = oc.sizeSquared() - rsq;

    // discriminant
    const S dis = b * b - S{4} * a * c;
    if (dis < S { 0 }) {
        return std::nullopt;
    } else if (dis == 0) {
        VS its = org + dir * (-b / (S{2} * a));
        return std::make_pair(its, its);
    }

    return std::make_pair(
        org + dir * (-b + std::sqrt(dis)) / (S{2} * a),
        org + dir * (-b - std::sqrt(dis)) / (S{2} * a)
    );
}
}
}