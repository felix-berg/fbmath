// Created by felix on 10/16/23, 4:55 PM
#pragma once

#include "fbmath/number.hpp"
#include "fbmath/primitives/primitive-predeclaration.hpp"

#include <cstring>
#include <cassert>
#include <algorithm>
#include <array>

namespace fb {
namespace math {
template <int M, int N, typename T, typename U>
constexpr void transposeInto(
    Matrix<N, M, T>& transposed, const Matrix<M, N, U>& matrix
);

template <int M, int N, typename T>
struct Matrix {
    std::array<T, M * N> data;

    static constexpr int rows()    noexcept { return M; }
    static constexpr int columns() noexcept { return N; }

    static_assert(M >= 0, "Number of rows must be positive");
    static_assert(N >= 0, "Number of columns must be positive");

    constexpr Matrix()
        :data { { } }
    {
    }

    constexpr Matrix(std::initializer_list<const T[N]> list)
    {
        assert(list.size() == M);
        int i = 0;
        for (const auto& row: list) {
            for (int j = 0; j < N; ++j)
                data[i * N + j] = row[j];
            ++i;
        }
    }

    template <typename U>
    constexpr Matrix(const Matrix<M, N, U>& other)
        requires MorePreciseThan<T, U>
    {
        for (size_t i = 0; i < other.data.size(); ++i) {
            data[i] = static_cast<T>(other.data[i]);
        }
    }

    template <typename U>
    constexpr Matrix<M, N, U> convertTo() const
        requires std::convertible_to<T, U>
    {
        Matrix<M, N, U> mat;
        for (size_t i = 0; i < mat.data.size(); ++i) {
            mat.data[i] = static_cast<U>(data[i]);
        }
        return mat;
    }

    constexpr operator Vec2<T>() const noexcept
        requires (M == 2 && N == 1)
    {
        return std::bit_cast<Vec2<T>>(*this);
    }

    constexpr operator Vec3<T>() const noexcept
        requires (M == 3 && N == 1)
    {
        return std::bit_cast<Vec3<T>>(*this);
    }

    template <typename U = T>
    constexpr Matrix<N, M, U> transposed() const
        requires std::convertible_to<T, U>
    {
        Matrix<N, M, U> t;
        transposeInto(t, *this);
        return t;
    }

    constexpr bool symmetric() const noexcept
    {
        if constexpr (M != N)
            return false;
        else {
            for (int i = 0; i < N; ++i)
                for (int j = i + 1; j < N; ++j)
                    if ((*this)[i, j] != (*this)[j, i])
                        return false;
            return true;
        }
    }

    constexpr bool diagonal() const noexcept
        requires (!std::floating_point<T>)
    {
        if constexpr (M != N)
            return false;
        else {
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    if (i != j && (*this)[i, j] != T(0))
                        return false;
            return true;
        }
    }

    constexpr bool diagonal(T delta = 0.05f) const noexcept
        requires std::floating_point<T>
    {
        if constexpr (M != N)
            return false;
        else {
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    if (i != j &&
                        (*this)[i, j] < T(0) - delta &&
                        (*this)[i, j] > T(0) + delta)
                        return false;
            return true;
        }
    }

    constexpr T& operator[](int i, int j) noexcept
    {
        return data[i * N + j];
    }

    constexpr const T& operator[](int i, int j) const noexcept
    {
        return data[i * N + j];
    }

    constexpr T& operator[](int i) noexcept
        requires (M == 1 || N == 1)
    {
        return data[i];
    }

    constexpr const T& operator[](int i) const noexcept
        requires (M == 1
        || N == 1)
    {
        return data[i];
    }

    template <typename U>
    constexpr Matrix& operator+=(
        const Matrix<M, N, U>& other) noexcept
    {
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                (*this)[i, j] += other[i, j];
        return *this;
    }

    template <typename U>
    constexpr Matrix& operator-=(
        const Matrix<M, N, U>& other) noexcept
    {
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                (*this)[i, j] -= other[i, j];
        return *this;
    }

    template <typename S>
    constexpr Matrix& operator*=(S s) noexcept
    {
        for (T& elm: data)
            elm *= s;
        return *this;
    }

    template <typename S>
    constexpr Matrix& operator/=(S s) noexcept
    {
        for (T& elm: data)
            elm /= s;
        return *this;
    }

    constexpr Matrix operator+() const noexcept
    {
        Matrix result;
        for (int i = 0; i < data.size(); ++i)
            result.data[i] = +data[i];
    }

    constexpr Matrix operator-() const noexcept
    {
        Matrix result;
        for (int i = 0; i < data.size(); ++i)
            result.data[i] = -data[i];
    }

    template <typename U>
    constexpr bool operator==(const Matrix<M, N,
        U>& other) const noexcept
        requires std::equality_comparable_with<T, U>
    {
        return std::equal(begin(), end(), other.begin(), other.end());
    }

    template <typename U>
    constexpr bool operator!=(const Matrix<M, N, U>& other) const noexcept
        requires std::equality_comparable_with<T, U>
    {
        return !std::equal(begin(), end(), other.begin(), other.end());
    }

    constexpr auto begin() noexcept { return data.begin(); }

    constexpr auto begin() const noexcept { return data.cbegin(); }

    constexpr auto end() noexcept { return data.end(); }

    constexpr auto end() const noexcept { return data.cend(); }


    static constexpr Matrix identity()
        requires (M == N)
    {
        Matrix m;
        for (int i = 0; i < M; ++i)
            m[i, i] = 1;
        return m;
    }

    static constexpr Matrix all(const T& elm)
    {
        Matrix m;
        std::fill(m.begin(), m.end(), elm);
        return m;
    }
};

template <int M, int N, typename T, typename U>
constexpr auto operator+(const Matrix<M, N, T>& m1, const Matrix<M, N, U>& m2)
{
    using R = MorePreciseType<T, U>;
    Matrix<M, N, R> r = m1;
    return (r += m2);
}

template <int M, int N, typename T, typename U>
constexpr auto operator-(const Matrix<M, N, T>& m1, const Matrix<M, N, U>& m2)
{
    using R = MorePreciseType<T, U>;
    Matrix<M, N, R> r = m1;
    return (r -= m2);
}

template <int M, int N, typename T, typename S>
constexpr auto operator*(const Matrix<M, N, T>& m1, S s)
{
    using R = MorePreciseType<T, S>;
    Matrix<M, N, R> r = m1;
    return (r *= static_cast<R>(s));
}

template <int M, int N, typename T, typename S>
constexpr auto operator/(const Matrix<M, N, T>& m1, S s)
{
    using R = MorePreciseType<T, S>;
    Matrix<M, N, R> r = m1;
    return (r /= static_cast<R>(s));
}

template <int M, int N, typename T, typename S>
constexpr auto operator*(S s, const Matrix<M, N, T>& m1)
{
    return m1 * s;
}

constexpr bool overlaps(
    const void* b1, const void* e1, const void* b2, const void* e2) noexcept
{
    return (b2 <= b1 && b1 < e2) ||
        (b1 <= b2 && b2 < e1);
}

template <int M, int N, typename T, typename U>
constexpr void transposeInto(
    Matrix<N, M, T>& transposed, const Matrix<M, N, U>& matrix)
    requires std::convertible_to<U, T>
{
    assert(
        "The data of the matrices must not overlap!" &&
            !overlaps(
                transposed.begin(), transposed.end(),
                matrix.begin(), matrix.end())
    );

    for (int j = 0; j < N; ++j)
        for (int i = 0; i < M; ++i)
            transposed[j, i] = matrix[i, j];
}

template <int M, int R, int N, typename T, typename U, typename S>
constexpr void multiplyInto(
    Matrix<M, N, T>& result,
    const Matrix<M, R, U>& m1,
    const Matrix<R, N, S>& m2
) noexcept requires std::convertible_to<T, S> && std::convertible_to<U, S>
{
    assert(
        "The data of the result matrix and the must not overlap!" &&
            !overlaps(
                result.begin(), result.end(),
                m1.begin(), m1.end()
            ) && !overlaps(
            result.begin(), result.end(),
            m2.begin(), m2.end()
        ));

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            result[i, j] = static_cast<S>(0);
            for (int r = 0; r < R; ++r) {
                result[i, j] +=
                    static_cast<S>(m1[i, r]) * static_cast<S>(m2[r, j]);
            }
        }
    }
}

template <int M, int R, int N, typename T, typename U>
constexpr auto operator*(const Matrix<M, R, T>& m1,
    const Matrix<R, N, U>& m2) noexcept
{
    Matrix<M, N, MorePreciseType<T, U>> res;
    multiplyInto(res, m1, m2);
    return res;
}

template <typename T>
using Mat2 [[maybe_unused]] = Matrix<2, 2, T>;
using Mat2i = Mat2<int>;
using Mat2f = Mat2<float>;
using Mat2d = Mat2<double>;

template <typename T>
using Mat3 [[maybe_unused]] = Matrix<3, 3, T>;
using Mat3i = Mat3<int>;
using Mat3f = Mat3<float>;
using Mat3d = Mat3<double>;

template <typename T>
using Mat4 [[maybe_unused]] = Matrix<4, 4, T>;
using Mat4i = Mat4<int>;
using Mat4f = Mat4<float>;
using Mat4d = Mat4<double>;
}
}