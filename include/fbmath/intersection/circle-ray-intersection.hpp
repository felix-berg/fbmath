// Created by felix on 11/13/22, 2:24 PM.
#pragma once

#include "fbmath/ray.hpp"
#include "fbmath/circle.hpp"
#include "fbmath/ostream_interop.hpp"

#include <cassert>

namespace fb {
namespace math {

template <Number N>
using CircleRayIntersection = std::pair<Vec2<N>, Vec2<N>>;

template <Number R, Number C>
constexpr auto intersection(
    const Ray<Vec2<R>>& ray, const Circle<C>& circle)
    -> std::optional<CircleRayIntersection<MorePreciseType<R, C>>>
{
    using S = MorePreciseType<R, C>;
    using VecS = Vec2<S>;

    const VecS u = static_cast<VecS>(circle.c) - static_cast<VecS>(ray.org);
    VecS r = ray.dir;
    const VecS ur = projection(u, r);
    const VecS d = u - ur;

    const S radsq = S(circle.r) * S(circle.r);
    const S dsq = d.template sizeSquared<S>();
    if (dsq > radsq) /* If d is outside circle, no points*/
        return std::nullopt;

    const VecS pur = ray.org + ur;

    if (dsq == radsq) [[unlikely]] {
        return std::make_pair(pur, pur);
    } else [[likely]] {
        /* Ray has to be normalized to make formula work */
        r.normalize();

        const S rt = std::sqrt(radsq - dsq);
        const VecS p1 = pur + rt * r;
        const VecS p2 = pur - rt * r;
        return std::make_pair(
            p1, p2
        );
    }
}
}
}