// Created by felix on 11/12/22, 5:53 PM.
#pragma once
#include <number.hpp>
#include <cstdint>
#include <concepts>
#include <cmath>

/* TODO remove */
#include <vector>

namespace fbmath {
template <Number N>
struct Vec3 {
    N x, y, z;

    constexpr Vec3() noexcept = default;
    constexpr Vec3(const N _x, const N _y, const N _z) noexcept
        : x { _x }, y { _y }, z { _z } { };

    template <NonNarrowingConvertibleTo<N> O>
    constexpr Vec3(const O _x, const O _y, const O _z) noexcept
        : x { static_cast<N>(_x) },
          y { static_cast<N>(_y) },
          z { static_cast<N>(_z) }
  { };

    template <NonNarrowingConvertibleTo<N> O>
    constexpr Vec3(const Vec3<O>& other) noexcept
        : x { static_cast<N>(other.x) },
          y { static_cast<N>(other.y) },
          z { static_cast<N>(other.z) }
    { };

    template <NonNarrowingConvertibleTo<N> O>
    constexpr operator Vec3<O>() const noexcept
    {
        return Vec3<O>(static_cast<O>(x), static_cast<O>(y), static_cast<O>(z));
    }

    template <Number O>
    /// \brief Force narrowing conversion from type N to O
    /// \tparam O Type to force upon the resulting vector.
    /// \return Copy of vector with given Number type.
    constexpr Vec3<O> convertTo() const noexcept
    {
        return Vec3<O>(static_cast<O>(x), static_cast<O>(y), static_cast<O>(z));
    };

    template <Number SizeType = double>
    constexpr SizeType size() const noexcept
    {
        return std::sqrt(static_cast<SizeType>(x * x + y * y + z * z));
    }

    constexpr N sizeSquared() const noexcept
    {
        return x * x + y * y + z * z;
    }

    constexpr friend bool operator==(const Vec3&, const Vec3&) = default;
    constexpr friend bool operator!=(const Vec3&, const Vec3&) = default;
};

template <Number N, Number O>
constexpr bool operator==(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    using T = MorePreciseType<N, O>;
    return static_cast<Vec3<T>>(v) == static_cast<Vec3<T>>(u);
}

template <Number N, Number O>
constexpr bool operator!=(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    using T = MorePreciseType<N, O>;
    return static_cast<Vec3<T>>(v) != static_cast<Vec3<T>>(u);
}

template <Number N>
constexpr N dotProduct(const Vec3<N>& v, const Vec3<N>& u) noexcept
{
    return v.x * u.x + v.y * u.y + v.z * u.z;
}

using V3i   [[maybe_unused]] = Vec3<int>;
using V3u   [[maybe_unused]] = Vec3<uint32_t>;
using V3i32 [[maybe_unused]] = Vec3<int32_t>;
using V3u32 [[maybe_unused]] = Vec3<uint32_t>;
using V3l   [[maybe_unused]] = Vec3<long>;
using V3ul  [[maybe_unused]] = Vec3<unsigned long>;
using V3i64 [[maybe_unused]] = Vec3<int64_t>;
using V3u64 [[maybe_unused]] = Vec3<uint64_t>;
using V3f   [[maybe_unused]] = Vec3<float>;
using V3f32 [[maybe_unused]] = Vec3<float>;
using V3f64 [[maybe_unused]] = Vec3<double>;
using V3d   [[maybe_unused]] = Vec3<double>;

} // fbmath
