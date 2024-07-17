// Created by felix on 11/12/22, 5:53 PM.
#pragma once
#include "fbmath/number.hpp"
#include "fbmath/contants.hpp"
#include "fbmath/primitives/primitive-predeclaration.hpp"

#include <cstdint>
#include <concepts>
#include <cmath>
#include <cassert>

namespace fb {
namespace math {
template <typename N, std::floating_point SizeType = N>
    requires std::convertible_to<SizeType, N>
constexpr SizeType size(const Vec2<N>& v) noexcept;

template <typename N>
struct Vec2 {
    using Type = N;
    N x, y;

    constexpr Vec2(const N _x, const N _y) noexcept
        :x { _x }, y { _y } { };

    constexpr Vec2() noexcept
        :x { }, y { } { };

    template <typename O>
        requires MorePreciseThan<N, O>
    constexpr Vec2(const O _x, const O _y) noexcept
        : x { static_cast<N>(_x) },
          y { static_cast<N>(_y) } { };

    template <typename O>
    constexpr operator Vec2<O>() const noexcept
        requires MorePreciseThan<O, N>
    {
        return Vec2<O>(static_cast<O>(x), static_cast<O>(y));
    }

    constexpr N size() const noexcept
        requires std::floating_point<N>
    {
        return size<N>(*this);
    }

    constexpr N sizeSquared() const noexcept
    {
        return x * x + y * y;
    }

    template <std::floating_point AngleType = double>
    constexpr AngleType angle() const noexcept
        requires std::floating_point<N>
    {
        /* a = cos(x / sz) */
        AngleType angle = std::acos(static_cast<AngleType>(x) / size<AngleType>());

        bool pX = x >= N(); /* x positive? */
        bool pY = y >= N(); /* y positive? */

             if (pX && pY)   return angle;              /* 1st quadrant */
        else if (!pX && pY)  return angle;              /* 2nd quadrant */
        else if (!pX) return twoPi<AngleType> - angle;  /* 3rd quadrant */
        else return twoPi<AngleType> - angle;           /* 4th quadrant */
    }

    template <std::floating_point AngleType = double>
    constexpr void setAngle(AngleType angle) noexcept
    {
        *this = Vec2<N>::fromAngle(angle, size());
    }

    template <std::floating_point SizeType = double>
    constexpr void setSize(SizeType sz) noexcept
    {
        SizeType xnum = static_cast<SizeType>(x * sz);
        SizeType ynum = static_cast<SizeType>(y * sz);
        SizeType oldsz = size<SizeType>();

        x = static_cast<N>(xnum / oldsz);
        y = static_cast<N>(ynum / oldsz);
    }

    constexpr void normalize() noexcept
        requires std::floating_point<N>
    {
        *this /= size();
    }

    constexpr Vec2 unit() const noexcept
    requires std::floating_point<N>
    {
        return *this / size();
    }

    template <std::floating_point SizeType = double,
        std::floating_point AngleType = double>
    static constexpr Vec2 fromAngle(AngleType angle,
        SizeType sz = 1.0f) noexcept
    {
        N x = static_cast<N>(std::cos(angle) * sz);
        N y = static_cast<N>(std::cos(angle) * sz);
        return { x, y };
    }

    template <typename O>
        requires std::convertible_to<N, O>
    static constexpr Vec2 from(const Vec2<O>& v) noexcept
    {
        return {
            static_cast<N>(v.x),
            static_cast<N>(v.y)
        };
    }

    template <std::convertible_to<N> O>
    static constexpr Vec2 all(O v) noexcept
    {
        return { static_cast<N>(v), static_cast<N>(v) };
    }

    constexpr friend bool operator==(const Vec2&,
        const Vec2&) noexcept = default;
    constexpr friend bool operator!=(const Vec2&,
        const Vec2&) noexcept = default;

    template <typename O = N>
    constexpr Vec2& operator+=(const Vec2<O>& v) noexcept
    {
        return (*this = *this + v);
    }

    template <typename O = N>
    constexpr Vec2& operator-=(const Vec2<O>& v) noexcept
    {
        return (*this = *this - v);
    }

    template <typename S>
    constexpr Vec2& operator*=(const S factor) noexcept
    {
        return (*this = *this * factor);
    }

    template <typename S>
    constexpr Vec2& operator/=(const S factor) noexcept
    {
        return (*this = *this / factor);
    }

    constexpr Vec2 operator+() const noexcept {
        return *this;
    }

    constexpr Vec2 operator-() const noexcept {
        return { -x, -y };
    }
};

template <typename N, typename O, typename R>
constexpr Vec2<R> add(const Vec2<N>& v, const Vec2<O>& u) noexcept
{
    return {
        static_cast<R>(v.x) + static_cast<R>(u.x),
        static_cast<R>(v.y) + static_cast<R>(u.y)
    };
}

template <typename N, typename O, typename R>
constexpr Vec2<R> sub(const Vec2<N>& v, const Vec2<O>& u) noexcept
{
    return {
        static_cast<R>(v.x) - static_cast<R>(u.x),
        static_cast<R>(v.y) - static_cast<R>(u.y)
    };
}

template <typename N, typename S, typename R>
constexpr Vec2<R> mult(const Vec2<N>& v, const S factor) noexcept
{
    return {
        static_cast<R>(v.x) * static_cast<R>(factor),
        static_cast<R>(v.y) * static_cast<R>(factor)
    };
}

template <typename N, typename S, typename R>
constexpr Vec2<R> div(const Vec2<N>& v, const S factor) noexcept
{
    return {
        static_cast<R>(v.x) / static_cast<R>(factor),
        static_cast<R>(v.y) / static_cast<R>(factor)
    };
}

template <typename N, typename O>
 constexpr Vec2<MorePreciseType<N, O>> operator+(const Vec2<N>& v,
    const Vec2<O>& u)
noexcept
{
     return add<N, O, MorePreciseType<N, O>>(v,u);
}

template <typename N, typename O>
 constexpr Vec2<MorePreciseType<N, O>> operator-(const Vec2<N>& v,
    const Vec2<O>& u)
noexcept
{
     return sub<N, O, MorePreciseType<N, O>>(v, u);
}

template <typename N, typename S>
 constexpr Vec2<MorePreciseType<N, S>> operator*(const Vec2<N>& v,
    const S factor) noexcept
{
    return mult<N, S, MorePreciseType<N, S>>(v, factor);
}

template <typename N, typename S>
 constexpr Vec2<MorePreciseType<N, S>> operator/(const Vec2<N>& v,
    const S factor) noexcept
{
     return div<N, S, MorePreciseType<N,S>>(v, factor);
}

template <typename N, typename S>
 constexpr auto operator*(const S factor, const Vec2<N>& v) noexcept
{
    return mult<N, S, MorePreciseType<N, S>>(v, factor);
}

template <typename N, typename O>
requires std::equality_comparable_with<N, O>
constexpr bool operator==(const Vec2<N>& v, const Vec2<O>& u) noexcept
{
    return v.x == u.x && v.y == u.y;
}

template <typename N, typename O>
requires std::equality_comparable_with<N, O>
constexpr bool operator!=(const Vec2<N>& v, const Vec2<O>& u) noexcept
{
    return v.x != u.x || v.y != u.y;
}

template <typename N, std::floating_point SizeType>
    requires std::convertible_to<SizeType, N>
constexpr SizeType size(const Vec2<N>& v) noexcept
{
    return std::sqrt(Vec2<SizeType>::from(v).sizeSquared());
}

template <typename N>
constexpr N dotProduct(const Vec2<N>& v, const Vec2<N>& u) noexcept
{
    return v.x * u.x + v.y * u.y;
}

template <std::floating_point S = double, std::convertible_to<S> N>
/// \tparam S Type of resulting angle
/// \return smallest angle between vectors v, u in radians
constexpr S angleBetween(const Vec2<N>& v, const Vec2<N>& u) noexcept
{
    /* cos^-1((v · u)/(|v| * |u|)) */
    S over = dotProduct(v, u);

    /* √v * √u = √(v * u) */
    S under = std::sqrt(static_cast<S>(
        v.sizeSquared() * u.sizeSquared()));

    return std::acos(over / under);
}

using V2i   [[maybe_unused]] = Vec2<int>;
using V2u   [[maybe_unused]] = Vec2<uint32_t>;
using V2i32 [[maybe_unused]] = Vec2<int32_t>;
using V2u32 [[maybe_unused]] = Vec2<uint32_t>;
using V2l   [[maybe_unused]] = Vec2<long>;
using V2ul  [[maybe_unused]] = Vec2<unsigned long>;
using V2i64 [[maybe_unused]] = Vec2<int64_t>;
using V2u64 [[maybe_unused]] = Vec2<uint64_t>;
using V2f   [[maybe_unused]] = Vec2<float>;
using V2d   [[maybe_unused]] = Vec2<double>;
}
}
