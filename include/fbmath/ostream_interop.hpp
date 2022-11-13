// Created by felix on 11/12/22, 10:18 PM.
#pragma once

#include <ostream>
#include <fbmath/2D/vec2.hpp>
#include <fbmath/3D/vec3.hpp>
#include <fbmath/2D/boundingbox.hpp>
#include <fbmath/2D/circle.hpp>

namespace fbmath {

template <typename N>
std::ostream & operator <<(std::ostream& os, const Vec2<N>& v) noexcept {
    return os << '(' << v.x << ", " << v.y << ')';
}

template <typename N>
std::ostream & operator <<(std::ostream& os, const Vec3<N>& v) noexcept {
    return os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}

template <typename N>
std::ostream & operator<<(std::ostream& os, const BoundingBox<N>& bb) noexcept {
    return os << "[tl: " << bb.tl << ", br: " << bb.br << "]";
}

template <typename N>
std::ostream& operator<<(std::ostream& os, const Ray<N>& ray) noexcept {
    return os << "[org: " << ray.org << ", dir: " << ray.dir << "]";
}

template <typename N, typename R>
std::ostream& operator<<(std::ostream& os, const Circle<N, R>& c) noexcept {
    return os << "[c: " << c.c << ", r: " << c.r << "]";
}

} // namespace fbmath