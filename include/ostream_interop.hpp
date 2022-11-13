// Created by felix on 11/12/22, 10:18 PM.
#pragma once

#include <ostream>
#include "2D/vec2.hpp"
#include "3D/vec3.hpp"
#include "2D/boundingbox.hpp"

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
    return os << "[tl: " << bb.tl << ", br: " << bb.br << "]\n";
}

} // namespace fbmath