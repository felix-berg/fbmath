// Created by felix on 11/12/22, 11:35 PM.
#pragma once

#include <fbmath/2D/vec2.hpp>
#include <fbmath/intersection.hpp>
#include <optional>

namespace fb {
namespace math {
template <Number N>
struct Ray {
    Vec2<N> org, dir;

    constexpr Ray() = default;

    constexpr Ray(const Vec2<N>& _org, const Vec2<N>& _dir)
        :org { _org }, dir { _dir } { };

    constexpr Ray(N ox, N oy, N dx, N dy)
        :org { ox, oy }, dir { dx, dy } { };

    template <std::floating_point ParamType = double>
    constexpr Vec2<N> get(ParamType param) const noexcept
    {
        return org + dir * param;
    }
};

namespace impl {
template <Number N, Number O> requires std::floating_point<
    MorePreciseType<N, O>>
struct IntersectionTypeS<Ray<N>, Ray<O>> {
    using Type = std::optional<Vec2<MorePreciseType<N, O>>>;
};

template <Number N, Number O>
struct IntersectionTypeS<Ray<N>, Ray<O>> {
    using Type = std::optional<V2d>;
};
}

template <std::floating_point ParamType>
/// \tparam ParamType type to work with
/// \param p1 Origin vector of first ray
/// \param r Direction vector of first ray
/// \param p2 Origin vector of second ray
/// \param s Direction vector of second ray
/// \return parameter for intersection of the first ray.
constexpr std::optional<ParamType> getIntersectionParam(
    const Vec2<ParamType>& p1, const Vec2<ParamType>& r,
    const Vec2<ParamType>& p2, const Vec2<ParamType>& s)
{
    ParamType nm = s.y * (p1.x - p2.x) - s.x * (p1.y - p2.y);
    ParamType dn = r.y * s.x - r.x * s.y;
    if (dn == ParamType(0.0))
        return std::nullopt;
    return nm / dn;
}

template <Number N, Number O>
constexpr IntersectionType<Ray<N>, Ray<O>> intersection(
    const Ray<N>& r1, const Ray<O>& r2) noexcept
{
    using Opt = IntersectionType<Ray<N>, Ray<O>>;
    using T = Opt::value_type::Type;
    const auto opt = getIntersectionParam<T>(
        Vec2<T>::from(r1.org),
        Vec2<T>::from(r1.dir),
        Vec2<T>::from(r2.org),
        Vec2<T>::from(r2.dir)
    );

    if (!opt.has_value())
        return std::nullopt;
    else
        return r1.get(*opt);
}
}
}; // namespace