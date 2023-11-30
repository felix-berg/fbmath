// Created by felix on 11/12/22, 10:34 PM.
#pragma once

#include "vec2.hpp"
#include <cassert>
#include <vector>

namespace fb {
namespace math {
/// \brief Axis-aligned bounding box
///        top-left inclusive, bottom right exclusive
template <typename N>
struct BoundingBox {
    Vec2<N> tl; /* top left */
    Vec2<N> br; /* bottom right */

    constexpr BoundingBox(const Vec2<N>& _tl, const Vec2<N>& _br) noexcept
        : tl { _tl }, br { _br }
    {
        assert(tl.x <= br.x && tl.y <= br.y);
    };

    constexpr BoundingBox() : BoundingBox({}, {}) { };
    constexpr BoundingBox(N x1, N y1, N x2, N y2) : BoundingBox({x1, y1}, {x2, y2}) { };

    template <typename O = N>
    constexpr bool contains(const Vec2<O>& v) const noexcept
    {
        return inRange(v.x, tl.x, br.x) && inRange(v.y, tl.y, br.y);
    }

    template <Number O = N>
    constexpr bool overlapsWith(const BoundingBox<O>& other) const noexcept
    {
        return
            (inRange(tl.x, other.tl.x, other.br.x)
                || inRange(br.x, other.tl.x, other.br.x)) &&
            (inRange(tl.y, other.tl.y, other.br.y)
             || inRange(br.y, other.tl.y, other.br.y));
    }
private:
    template <Number T = N, Number U = N>
     static constexpr bool inRange(T val, U min, U max) noexcept {
        return val >= min && val < max;
    }
};

} // namespace fbmath
}