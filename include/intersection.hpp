// Created by felix on 11/12/22, 11:48 PM.
#pragma once

#include <concepts>

namespace fbmath {
namespace impl {
template <typename T, typename U>
struct IntersectionTypeS {
    static_assert(std::same_as<void, T>, "Intersection not yet implemented.");
};
}

template <typename T, typename U>
using IntersectionType = impl::IntersectionTypeS<T, U>::Type;

template <typename T, typename U>
constexpr IntersectionType<T, U> intersection(const T& t, const U& u) noexcept
{
    static_assert(std::same_as<void, T>, "Error: intersection not yet implemented.");
};
}; // namespace