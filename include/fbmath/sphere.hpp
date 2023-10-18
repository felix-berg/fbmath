// Created by felix on 10/18/23, 12:27 PM
#pragma once

#include "number.hpp"
#include "vec3.hpp"

namespace fb { namespace math {
template <Number N>
struct Sphere {
    Vec3<N> c;
    N r;
};
}
}