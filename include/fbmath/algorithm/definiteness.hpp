// Created by felix on 11/30/23, 9:01 PM
#pragma once

#include <iostream>
#include "fbmath/primitives/matrix.hpp"
#include "fbmath/ostream_latex.hpp"

namespace fb { namespace math {

// Diagonalize a symmetric matrix using the algorithm described in
// Section 8.6 - https://edtech.dk/IMO23/hessian.html#852c95b4-3152-40e8-b141-6a6d5a4374fa
// print the latex matrices that are used
template <int N, typename T>
void diagonalizeAndPrintSteps(Matrix<N, N, T>& m)
{
    static constexpr Matrix<N, N, T> id = Matrix<N, N, T>::identity();
    Matrix<N, N, T> combinedB = id;
    Matrix<N, N, T> b;

    int i = 0;
    int stringIndex = 1;
    std::string displayStr = "A";

    while (i < N - 1) {
        b = id;

        // check if there are no entries to eliminate in the row
        bool allZero = true;
        for (int j = i + 1; allZero && j < N; ++j)
            allZero &= m[i, j] == 0;

        // nothing to eliminate -> move to next diagonal
        if (allZero) {
            i++;
            continue;
        }

        if (m[i, i] == 0) {
            // no element to eliminate with
            // find element in first row/column to swap with
            for (int j = i + 1; j < N; ++j)
                if (m[i, j] != 0)
                    b[j, i] = 1;
        }
        else {
            for (int j = i + 1; j < N; ++j) {
                if (m[i, j] == 0)
                    continue;

                b[i, j] = -m[i, j] / m[i, i];
            }

            // multiplying B^T·A·B will zero out first
            // row and column (except for diagonal)
            i++;
        }

        combinedB = combinedB * b;
        m = b.transposed() * m * b;

        std::string bstr = "B_{" + std::to_string(stringIndex) + "}";
        std::cout << "Multiplying with $" + bstr + "$\n"
                  << latexFormat << b;
        displayStr = bstr + "^\\top " + displayStr + bstr;
        std::cout << "Calculating " << displayStr << "$ = \n"
                  << latexFormat << m;
        stringIndex++;
    }

    std::cout << "Combined matrix B to diagonalize A is \n"
              << latexFormat << combinedB;
}

// Diagonalize a symmetric matrix using the algorithm described in
// Section 8.6 - https://edtech.dk/IMO23/hessian.html#852c95b4-3152-40e8-b141-6a6d5a4374fa
template <int N, typename T>
constexpr void diagonalize(Matrix<N, N, T>& m) noexcept
{
    static constexpr Matrix<N, N, T> id = Matrix<N, N, T>::identity();
    Matrix<N, N, T> b;

    int i = 0;
    while (i < N - 1) {
        b = id;

        // check if there are no entries to eliminate in the row
        bool allZero = true;
        for (int j = i + 1; allZero && j < N; ++j)
            allZero &= m[i, j] == 0;

        // nothing to eliminate -> move to next diagonal
        if (allZero) {
            i++;
            continue;
        }

        if (m[i, i] == 0) {
            // no element to eliminate with
            // find element in first row/column to swap with
            for (int j = i + 1; j < N; ++j)
                if (m[i, j] != 0)
                    b[j, i] = 1;
        }
        else {
            for (int j = i + 1; j < N; ++j) {
                if (m[i, j] == 0)
                    continue;

                b[i, j] = -m[i, j] / m[i, i];
            }

            // multiplying B^T·A·B will zero out first
            // row and column (except for diagonal)
            i++;
        }

        m = b.transposed() * m * b;
    }
}

// Diagonalize a symmetric matrix using the algorithm described in
// Section 8.6 - https://edtech.dk/IMO23/hessian.html#852c95b4-3152-40e8-b141-6a6d5a4374fa
template <int N, typename T>
constexpr Matrix<N, N, T> computeDiagonal(const Matrix<N, N, T>& m) noexcept
{
    auto cpy = m;
    diagonalize(cpy);
    return cpy;
}

// Diagonalize a symmetric matrix using the algorithm described in
// Section 8.6 - https://edtech.dk/IMO23/hessian.html#852c95b4-3152-40e8-b141-6a6d5a4374fa
// print the latex matrices that are used
template <int N, typename T>
constexpr Matrix<N, N, T> computeDiagonalWithSteps(const Matrix<N, N, T>& m) noexcept
{
    auto cpy = m;
    diagonalizeAndPrintSteps(cpy);
    return cpy;
}

template <int N, typename T>
constexpr bool positiveDiagonal(const Matrix<N, N, T>& m) noexcept
{
    for (int i = 0; i < N; ++i)
        if (m[i, i] <= T {0})
            return false;
    return true;
}

template <int N, typename T>
constexpr bool nonNegativeDiagonal(const Matrix<N, N, T>& m) noexcept
{
    for (int i = 0; i < N; ++i)
        if (m[i, i] < T {0})
            return false;
    return true;
}

template <int N, typename T>
constexpr bool positiveDefinite(const Matrix<N, N, T>& m) noexcept
{
    if (m.diagonal())
        return positiveDiagonal(m);
    return positiveDiagonal(computeDiagonal(m));
}

template <int N, typename T>
constexpr bool positiveSemiDefinite(const Matrix<N, N, T>& m) noexcept
{
    if (m.diagonal())
        return nonNegativeDiagonal(m);
    return nonNegativeDiagonal(computeDiagonal(m));
}
}}