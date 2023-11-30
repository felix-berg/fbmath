// Created by felix on 11/12/22, 5:53 PM.
#pragma once
#include <cstdint>
#include <concepts>
#include <cmath>

#include "fbmath/number.hpp"
#include "fbmath/primitives/primitive-predeclaration.hpp"

namespace fb {
namespace math {

template <typename N, std::floating_point S = N>
    requires std::convertible_to<S, N>
constexpr S size(const Vec3<N>& v) noexcept;

template <typename N>
struct Vec3 {
    N x, y, z;

    constexpr Vec3() noexcept = default;
    constexpr Vec3(const N _x, const N _y, const N _z) noexcept
        : x { _x }, y { _y }, z { _z } { };

    template <typename O>
        requires MorePreciseThan<N, O>
    constexpr Vec3(const O _x, const O _y, const O _z) noexcept
        : x { static_cast<N>(_x) },
          y { static_cast<N>(_y) },
          z { static_cast<N>(_z) }
  { };

    template <typename O>
    constexpr operator Vec3<O>() const noexcept
        requires MorePreciseThan<O, N>
    {
        return Vec2<O>(static_cast<O>(x), static_cast<O>(y), static_cast<O>(z));
    }

    constexpr N size() const noexcept
        requires std::floating_point<N>
    {
        return size<N>(*this);
    }

    constexpr N sizeSquared() const noexcept
    {
        return x * x + y * y + z * z;
    }

    constexpr Vec3 unit() const noexcept
        requires std::floating_point<N>
    {
        return *this / size();
    }

    constexpr void normalize() noexcept
        requires std::floating_point<N>
    {
        *this /= size();
    }

    template <std::convertible_to<N> O>
    static constexpr Vec3 from(const Vec3<O>& other) noexcept
    {
        return {
            static_cast<N>(other.x),
            static_cast<N>(other.y),
            static_cast<N>(other.z)
        };
    }

    template <std::convertible_to<N> O>
    static constexpr Vec3 all(O v) noexcept
    {
        return { static_cast<N>(v), static_cast<N>(v), static_cast<N>(v) };
    }

    constexpr friend bool operator==(const Vec3&, const Vec3&) = default;
    constexpr friend bool operator!=(const Vec3&, const Vec3&) = default;

    template <typename O = N>
    constexpr Vec3& operator+=(const Vec3<O>& v) noexcept
    {
        return (*this = *this + v);
    }

    template <typename O = N>
    constexpr Vec3& operator-=(const Vec3<O>& v) noexcept
    {
        return (*this = *this - v);
    }

    template <typename FactType>
    constexpr Vec3& operator*=(const FactType factor) noexcept
    {
        return (*this = *this * factor);
    }

    template <typename FactType>
    constexpr Vec3& operator/=(const FactType factor) noexcept
    {
        return (*this = *this / factor);
    }

    constexpr Vec3 operator+() const noexcept {
        return *this;
    }

    constexpr Vec3 operator-() const noexcept {
        return { -x, -y, -z };
    }
};

template <typename N, typename S = double>
    requires std::convertible_to<S, N>
constexpr S size(const Vec3<N>& v) noexcept
{
    return std::sqrt(Vec3<S>::from(v).sizeSquared());
}


template <typename N, typename O, typename R>
constexpr Vec3<R> add(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    return {
        static_cast<R>(v.x) + static_cast<R>(u.x),
        static_cast<R>(v.y) + static_cast<R>(u.y),
        static_cast<R>(v.z) + static_cast<R>(u.z),
    };
}

template <typename N, typename O, typename R>
constexpr Vec3<R> sub(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    return {
        static_cast<R>(v.x) - static_cast<R>(u.x),
        static_cast<R>(v.y) - static_cast<R>(u.y),
        static_cast<R>(v.z) - static_cast<R>(u.z),
    };
}

template <typename N, typename S, typename R>
constexpr Vec3<R> mult(const Vec3<N>& v, const S factor) noexcept
{
    return {
        static_cast<R>(v.x) * static_cast<R>(factor),
        static_cast<R>(v.y) * static_cast<R>(factor),
        static_cast<R>(v.z) * static_cast<R>(factor),
    };
}

template <typename N, typename S, typename R>
constexpr Vec3<R> div(const Vec3<N>& v, const S factor) noexcept
{
    return {
        static_cast<R>(v.x) / static_cast<R>(factor),
        static_cast<R>(v.y) / static_cast<R>(factor),
        static_cast<R>(v.z) / static_cast<R>(factor),
    };
}

template <typename N, typename O>
constexpr Vec3<MorePreciseType<N, O>> operator+(const Vec3<N>& v,
    const Vec3<O>& u)
noexcept
{
    return add<N, O, MorePreciseType<N, O>>(v,u);
}

template <typename N, typename O>
constexpr Vec3<MorePreciseType<N, O>> operator-(const Vec3<N>& v,
    const Vec3<O>& u)
noexcept
{
    return sub<N, O, MorePreciseType<N, O>>(v, u);
}

template <typename N, typename S>
constexpr Vec3<MorePreciseType<N, S>> operator*(const Vec3<N>& v,
    const S factor) noexcept
{
    return mult<N, S, MorePreciseType<N, S>>(v, factor);
}

template <typename N, typename S>
constexpr Vec3<MorePreciseType<N, S>> operator/(const Vec3<N>& v,
    const S factor) noexcept
{
    return div<N, S, MorePreciseType<N,S>>(v, factor);
}

template <typename N, typename S>
constexpr auto operator*(const S factor, const Vec3<N>& v) noexcept
{
    return mult<N, S, MorePreciseType<N, S>>(v, factor);
}

template <typename N, typename O>
    requires std::equality_comparable_with<N, O>
constexpr bool operator==(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    return v.x == u.x && v.y == u.y;
}

template <typename N, typename O>
    requires std::equality_comparable_with<N, O>
constexpr bool operator!=(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    return v.x != u.x || v.y != u.y;
}

template <typename N>
constexpr N dotProduct(const Vec3<N>& v, const Vec3<N>& u) noexcept
{
    return v.x * u.x + v.y * u.y + v.z * u.z;
}

template <typename N>
constexpr Vec3<N> crossProduct(const Vec3<N>& v, const Vec3<N>& u) noexcept
{
    return {
        v.y * u.z - v.z * u.y,
        v.z * u.x - v.x * u.z,
        v.x * u.y - v.y * u.x
    };
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
}