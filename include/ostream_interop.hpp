// Created by felix on 11/12/22, 10:18 PM.
#pragma once

#include <ostream>
#include <vec2.hpp>
#include <vec3.hpp>

namespace fbmath {

template <typename N>
std::ostream & operator <<(std::ostream& os, const Vec2<N>& v) noexcept {
    return os << '(' << v.x << ", " << v.y << ")\n";
}

template <typename N>
std::ostream & operator <<(std::ostream& os, const Vec3<N>& v) noexcept {
    return os << '(' << v.x << ", " << v.y << ", " << v.z << ")\n";
}

} // namespace fbmath