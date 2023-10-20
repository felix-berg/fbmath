// Created by felix on 10/20/23, 4:59 PM
#pragma once

#include "fbmath/primitives/ray.hpp"
#include "fbmath/primitives/plane.hpp"

namespace fb { namespace math {

template <Number P, Number R, std::floating_point T = MorePreciseType<P, R>>
std::optional<float> planeRayIntersectionParam(
    const Plane<P>& plane, const Ray<Vec3<R>>& ray) noexcept
{
    using VT = Vec3<T>;
    const auto od = VT::from(ray.org) + VT::from(ray.dir);
    const auto n = VT::from(plane.normal);
    const auto d = static_cast<T>(plane.d);

    return -d / (dotProduct(n, od));
}

template <Number P, Number R, std::floating_point T = MorePreciseType<P, R>>
std::optional<Vec3<T>> intersection(
    const Plane<P>& plane,
    const Ray<Vec3<R>>& ray
) noexcept
{
    using VT = Vec3<T>;
    const auto param = planeRayIntersectionParam(plane, ray);
    if (!param) return std::nullopt;
    return VT::from(ray.org) + VT::from(ray.dir) * (*param);
}

}}