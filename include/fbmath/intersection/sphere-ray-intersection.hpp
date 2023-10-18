// Created by felix on 10/18/23, 12:55 PM
#pragma once

#include <fbmath/sphere.hpp>
#include <fbmath/ray.hpp>

namespace fb { namespace math {

template <typename T>
using SphereRayIntersection =
    std::optional<std::pair<Vec3<T>, Vec3<T>>>;

template <Number S, Number R, std::floating_point T = MorePreciseType<S, R>>
constexpr std::optional<std::pair<T, T>> sphereRayIntersectionParams(
    const Sphere<S>& sphere,
    const Ray<Vec3<R>>& ray
) noexcept
{
    using VS = Vec3<T>;

    const VS org = VS::from(ray.org);
    const VS oc = org - VS::from(sphere.c);
    const VS dir = VS::from(ray.dir);
    const T rsq = static_cast<T>(sphere.r) * static_cast<T>(sphere.r);

    const T a = dir.sizeSquared();
    const T b = T{2} * (dotProduct(dir, oc));
    const T c = oc.sizeSquared() - rsq;

    const T dis = b * b - T{4} * a * c;
    if (dis < T{0}) return std::nullopt;
    else if (dis == 0) {
        T value = -b / (T{2} * a);
        return std::make_pair(value, value);
    } else {
        T sd = std::sqrt(dis);
        T a2 = T{2} * a;
        return std::make_pair(
            (-b + sd) / a2,
            (-b - sd) / a2
        );
    }
}

template <Number S, Number R, std::floating_point ResultType = MorePreciseType<S, R>>
constexpr SphereRayIntersection<ResultType> intersection(
    const Sphere<S>& sphere,
    const Ray<Vec3<R>>& ray
) noexcept
{
    const auto param = sphereRayIntersectionParams<
        S, R, ResultType>(sphere, ray);
    if (!param) return std::nullopt;

    Vec3<ResultType> o = static_cast<Vec3<ResultType>>(ray.org);
    Vec3<ResultType> d = static_cast<Vec3<ResultType>>(ray.dir);
    return std::make_pair(
          o + d * param->first,
          o + d * param->second
    );
}


}};