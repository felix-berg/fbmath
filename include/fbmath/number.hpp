// Created by felix on 11/12/22, 5:53 PM.
#pragma once
#include <concepts>
#include <utility>

namespace fb {
namespace math {
template <typename N>
concept Number = (std::integral<N> || std::floating_point<N>);

namespace impl {
template <std::floating_point N, std::integral O>
consteval auto getMorePreciseType() noexcept
{
    return N();
}

template <std::integral N, std::floating_point O>
consteval auto getMorePreciseType() noexcept
{
    return O();
}

template <Number N, Number O>
requires ((std::integral<N> && std::integral<O>) ||
    (std::floating_point<N> && std::floating_point<O>))
consteval auto getMorePreciseType() noexcept
{
    if constexpr (sizeof(N) > sizeof(O))
        return N();
    else
        return O();
}

template <typename T, typename U>
requires (!std::same_as<T, U> && !Number<T> && !Number<U>)
consteval auto getMorePreciseType()
{
    static_assert(std::same_as<T, void>, "More precise type couldn't be determined");
};

template <typename T, typename U>
requires (std::same_as<T, U> && !Number<T> && !Number<U>)
consteval auto getMorePreciseType()
{
    return T();
}

template <typename N, typename ... Ns>
consteval auto getMorePrecisetype() noexcept
{
    return getMorePreciseType<N, decltype(getMorePreciseType<Ns...>())>;
}
}

template <typename ... Ns>
using MorePreciseType = decltype(impl::getMorePreciseType<Ns...>());

template <typename N, typename C>
concept MorePreciseThan = Number<N> && Number<C>
    && std::same_as<MorePreciseType<N, C>, N>;

static_assert(
    Number<char> &&
        Number<short> &&
        Number<int> &&
        Number<long> &&
        Number<long long> &&
        Number<unsigned char> &&
        Number<unsigned short> &&
        Number<unsigned int> &&
        Number<unsigned long> &&
        Number<unsigned long long> &&
        Number<float> &&
        Number<double> &&
        Number<long double>
);
};
}