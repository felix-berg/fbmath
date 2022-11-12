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
struct Vec2 {
    N x, y;

    constexpr Vec2() noexcept = default;
    constexpr Vec2(const N _x, const N _y) noexcept
        : x { _x }, y { _y } { };

    template <NonNarrowingConvertibleTo<N> O>
    constexpr Vec2(const O _x, const O _y) noexcept
        : x { static_cast<N>(_x) },
          y { static_cast<N>(_y) } { };

    template <NonNarrowingConvertibleTo<N> O>
    constexpr Vec2(const Vec2<O>& other)
        : Vec2(static_cast<N>(other.x), static_cast<N>(other.y))
    { };

    template <NonNarrowingConvertibleTo<N> O>
    constexpr operator Vec2<O>() const noexcept
        {
        return Vec2<O>(static_cast<O>(x), static_cast<O>(y));
    }

    template <Number O>
    /// \brief Force narrowing conversion from type N to O
    /// \tparam O Type to force upon the resulting vector.
    /// \return Copy of vector with given Number type.
    constexpr Vec2<O> convertTo() const noexcept
    {
        return Vec2<O>(static_cast<O>(x), static_cast<O>(y));
    };

    template <Number SizeType = float>
    constexpr SizeType size() const noexcept
    {
        return std::sqrt(static_cast<SizeType>(x * x + y * y));
    }

    constexpr N sizeSquared() const noexcept
    {
        return x * x + y * y;
    }

    template <std::floating_point AngleType>
    constexpr AngleType angle() const noexcept
    {

    }

    template <std::floating_point AngleType>
    static constexpr Vec2 fromAngle(AngleType angle) noexcept
    {

    }

    constexpr friend bool operator==(const Vec2&, const Vec2&) = default;
    constexpr friend bool operator!=(const Vec2&, const Vec2&) = default;
};

template <Number N, Number O>
constexpr bool operator==(const Vec2<N>& v, const Vec2<O>& u)
{
    using T = MorePreciseType<N, O>;
    return static_cast<T>(v) == static_cast<T>(u);
}

template <Number N, Number O>
constexpr bool operator!=(const Vec2<N>& v, const Vec2<O>& u)
{
    using T = MorePreciseType<N, O>;
    return static_cast<T>(v) != static_cast<T>(u);
}

template <Number N>
constexpr N dotProduct(const Vec2<N>& v, const Vec2<N>& u)
{
    return v.x * u.x + v.y * u.y;
}

template <std::floating_point AngleType = float, Number N>
/// \tparam AngleType type of resulting angle
/// \return smallest angle between vectors v, u in radians
constexpr AngleType angleBetween(const Vec2<N>& v, const Vec2<N>& u)
{
    /* cos^-1((v · u)/(|v| * |u|)) */

    AngleType over  = dotProduct<AngleType>(v, u);
    /* √v * √u = √(v * u) */
    AngleType under = std::sqrt(static_cast<AngleType>(
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
using V2f32 [[maybe_unused]] = Vec2<float>;
using V2f64 [[maybe_unused]] = Vec2<double>;
using V2d   [[maybe_unused]] = Vec2<double>;

} // fbmath
