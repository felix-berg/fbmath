// Created by felix on 11/12/22, 10:18 PM.
#pragma once

#include <ostream>
#include "fbmath/primitives/vec2.hpp"
#include "fbmath/primitives/vec3.hpp"
#include "fbmath/primitives/boundingbox.hpp"
#include "fbmath/primitives/circle.hpp"
#include "fbmath/primitives/matrix.hpp"

namespace fb {
namespace math {

template <typename N>
std::ostream& operator <<(std::ostream& os, const Vec2<N>& v) noexcept {
    return os << '(' << v.x << ", " << v.y << ')';
}

template <typename N>
std::ostream& operator <<(std::ostream& os, const Vec3<N>& v) noexcept {
    return os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}

template <typename N>
std::ostream& operator<<(std::ostream& os, const BoundingBox<N>& bb) noexcept {
    return os << "[tl: " << bb.tl << ", br: " << bb.br << "]";
}

template <typename N>
std::ostream& operator<<(std::ostream& os, const Ray<N>& ray) noexcept {
    return os << "[org: " << ray.org << ", dir: " << ray.dir << "]";
}

template <typename N, typename R>
std::ostream& operator<<(std::ostream& os, const Circle<N>& c) noexcept
{
    return os << "[c: " << c.c << ", r: " << c.r << "]";
}

template <int M, int N, typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<M, N, T>& mv)
{
    os << "[\n";
    for (int i = 0; i < M; ++i) {
        os << "\t[";
        for (int j = 0; j < N; ++j)
            os << mv[i, j] << (j != N - 1 ? ", " : "");
        os << (i != M - 1 ? "],\n" : "]\n");
    }
    os << "]\n";
    return os;
}
}
} // namespace fbmath