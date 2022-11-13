// Created by felix on 11/13/22, 2:24 PM.
#pragma once

#include <2D/ray.hpp>
#include <2D/circle.hpp>
#include <ostream_interop.hpp>

#include <cassert>

namespace fbmath {
namespace impl {
template <Number N, Number O, Number R>
    requires std::floating_point<MorePreciseType<N, O, R>>
struct IntersectionTypeS<Ray<N>, Circle<O, R>> {
    using Num = MorePreciseType<N, O, R>;
    using Type = std::optional<std::pair<Vec2<Num>, Vec2<Num>>>;
};

template <Number N, Number O, Number R>
struct IntersectionTypeS<Ray<N>, Circle<O, R>> {
    using Type = std::optional<std::pair<V2d, V2d>>;
};
}

template <Number RayN, Number CN, Number RN>
constexpr IntersectionType<Ray<RayN>, Circle<CN, RN>> intersection(
    const Ray<RayN>& ray, const Circle<CN, RN>& circle)
{
    /* Choose the correct type of numbers to use.
     * Will be NonNarrowingConvertible to from RayN, CN and RN */
    using Optional = IntersectionType<Ray<RayN>, Circle<CN, RN>>;
    using Pair = Optional::value_type;
    using T = Pair::first_type::Type;
    using V2 = Vec2<T>;

    static_assert(
        NonNarrowingConvertibleTo<RayN, T> &&
        NonNarrowingConvertibleTo<CN, T> &&
        NonNarrowingConvertibleTo<RN, T>);

    const V2 u  = (V2) circle.c - (V2) ray.org;
          V2 r  = ray.dir;
    const V2 ur = projection(u, r);
    const V2 d = u - ur;

    const T radsq = T(circle.r) * T(circle.r);
    const T dsq = d.template sizeSquared<T>();
    if (dsq > radsq) /* If d is outside circle, no points*/
        return std::nullopt;


    const V2 pur = ray.org + ur;

    if (dsq == radsq) [[unlikely]] {
        return std::make_pair(pur, pur);
    } else [[likely]] {
        /* Ray has to be normalized to make formula work */
        r.normalize();

        const T rt = std::sqrt(radsq - dsq);
        const V2 p1 = pur + rt * r;
        const V2 p2 = pur - rt * r;
        return std::make_pair(
            p1, p2
        );
    }
}

}