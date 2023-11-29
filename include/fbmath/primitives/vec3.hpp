// Created by felix on 11/12/22, 5:53 PM.
#pragma once
#include <cstdint>
#include <concepts>
#include <cmath>

#include "fbmath/number.hpp"
#include "fbmath/primitives/primitive-predeclaration.hpp"

namespace fb {
namespace math {
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

    template <Number O>
    constexpr operator Vec2<O>() const noexcept
        requires NonNarrowingConvertibleTo<O, N>
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

    template <Number O>
    static constexpr Vec3 from(const Vec3<O>& other) noexcept
    {
        return {
            static_cast<N>(other.x),
            static_cast<N>(other.y),
            static_cast<N>(other.z)
        };
    }

    template <Number O>
    static constexpr Vec3 all(O v) noexcept
    {
        return { static_cast<N>(v), static_cast<N>(v), static_cast<N>(v) };
    }

    constexpr friend bool operator==(const Vec3&, const Vec3&) = default;
    constexpr friend bool operator!=(const Vec3&, const Vec3&) = default;

    template <Number O = N>
    constexpr Vec3& operator+=(const Vec3<O>& v) noexcept
    {
        return (*this = *this + v);
    }

    template <Number O = N>
    constexpr Vec3& operator-=(const Vec3<O>& v) noexcept
    {
        return (*this = *this - v);
    }

    template <Number FactType>
    constexpr Vec3& operator*=(const FactType factor) noexcept
    {
        return (*this = *this * factor);
    }

    template <Number FactType>
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

template <Number N, std::floating_point SizeType = N>
constexpr SizeType size(const Vec3<N>& v) noexcept
{
    return std::sqrt(Vec3<SizeType>::from(v).sizeSquared());
}

template <Number N, Number O>
constexpr Vec3<MorePreciseType<N, O>> operator+(const Vec3<N>& v,
    const Vec3<O>& u)
noexcept
{
    using T = MorePreciseType<N, O>;
    return {
        static_cast<T>(v.x) + static_cast<T>(u.x),
        static_cast<T>(v.y) + static_cast<T>(u.y),
        static_cast<T>(v.z) + static_cast<T>(u.z),
    };
}

template <Number N, Number O>
constexpr Vec3<MorePreciseType<N, O>> operator-(const Vec3<N>& v,
    const Vec3<O>& u)
noexcept
{
    using T = MorePreciseType<N, O>;
    return {
        static_cast<T>(v.x) - static_cast<T>(u.x),
        static_cast<T>(v.y) - static_cast<T>(u.y),
        static_cast<T>(v.z) - static_cast<T>(u.z),
    };
}

template <Number N, Number FacType>
constexpr Vec3<MorePreciseType<N, FacType>> operator*(const Vec3<N>& v,
    const FacType
    factor) noexcept
{
    using T = MorePreciseType<N, FacType>;
    return {
        static_cast<T>(v.x) * static_cast<T>(factor),
        static_cast<T>(v.y) * static_cast<T>(factor),
        static_cast<T>(v.z) * static_cast<T>(factor),
    };
}

template <Number FacType, Number N>
constexpr Vec3<MorePreciseType<N, FacType>> operator*(
    const FacType factor, const Vec3<N>& v) noexcept
{
    return v * factor;
}


template <Number N, Number FacType>
constexpr Vec3<MorePreciseType<N, FacType>> operator/(const Vec3<N>& v,
    const FacType factor) noexcept
{
    using T = MorePreciseType<N, FacType>;
    return {
        static_cast<T>(v.x) / static_cast<T>(factor),
        static_cast<T>(v.y) / static_cast<T>(factor),
        static_cast<T>(v.z) / static_cast<T>(factor),
    };
}

template <Number N, Number O>
    requires std::equality_comparable_with<N, O>
constexpr bool operator==(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    return v.x == u.x && v.y == u.y;
}

template <Number N, Number O>
    requires std::equality_comparable_with<N, O>
constexpr bool operator!=(const Vec3<N>& v, const Vec3<O>& u) noexcept
{
    return v.x != u.x || v.y != u.y;
}

template <Number N>
constexpr N dotProduct(const Vec3<N>& v, const Vec3<N>& u) noexcept
{
    return v.x * u.x + v.y * u.y + v.z * u.z;
}

template <Number N>
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