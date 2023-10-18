// Created by felix on 10/18/23, 12:55 PM
#pragma once

#include <fbmath/sphere.hpp>
#include <fbmath/ray.hpp>

namespace fb { namespace math {

template <typename T>
using SphereRayIntersection =
    std::optional<std::pair<Vec3<T>, Vec3<T>>>;

template <Number S, Number R, std::floating_point ResultType = MorePreciseType<S, R>>
constexpr SphereRayIntersection<ResultType> intersection(
    const Sphere<S>& sphere,
    const Ray<Vec3<R>>& ray
) noexcept
{
    using T = ResultType;
    using VS = Vec3<T>;

    const VS org = VS::from(ray.org);
    const VS oc = org - VS::from(sphere.c);
    const VS dir = static_cast<VS>(ray.dir);
    const T rsq = static_cast<T>(sphere.r) * static_cast<T>(sphere.r);

    const T a = dir.sizeSquared();
    const T b = 2 * (dotProduct(dir, oc));
    const T c = oc.sizeSquared() - rsq;

    // discriminant
    const T dis = b * b - 4 * a * c;
    if (dis < T { 0 }) {
        return std::nullopt;
    } else if (dis == 0) {
        VS its = org + dir * (-b / (2 * a));
        return std::make_pair(its, its);
    }

    return std::make_pair(
        org + dir * (-b + std::sqrt(dis)) / (2 * a),
        org + dir * (-b - std::sqrt(dis)) / (2 * a)
    );
}


}};