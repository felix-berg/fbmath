// Created by felix on 11/30/23, 8:45 PM
#pragma once

#include <ostream>
#include "fbmath/primitives/vec2.hpp"
#include "fbmath/primitives/vec3.hpp"
#include "fbmath/primitives/boundingbox.hpp"
#include "fbmath/primitives/circle.hpp"
#include "fbmath/primitives/matrix.hpp"

namespace fb { namespace math {

constexpr struct {} latexFormat;

struct LatexOStreamRef {
    std::ostream& os;
};
}}

fb::math::LatexOStreamRef operator<<(std::ostream& os, decltype(fb::math::latexFormat)&)
{
    return fb::math::LatexOStreamRef { os };
}

template <typename T>
fb::math::LatexOStreamRef operator<<(fb::math::LatexOStreamRef r, const T& t) noexcept
{
    return { r.os << t };
}

template <typename N>
fb::math::LatexOStreamRef operator<<(fb::math::LatexOStreamRef r, const fb::math::Vec2<N>& v) noexcept
{
    r << "\\begin{pmatrix}\n"
      << '\t' << v.x << "\\\\ " << v.y
      << "\n\\end{pmatrix}\n";
    return r;
}

template <typename N>
fb::math::LatexOStreamRef operator<<(fb::math::LatexOStreamRef r, const fb::math::Vec3<N>& v) noexcept
{
    r << "\\begin{pmatrix}\n"
      << '\t' << v.x << "\\\\ " << v.y << "\\\\ " << v.z
      << "\n\\end{pmatrix}\n";
    return r;
}

template <int M, int N, typename T>
fb::math::LatexOStreamRef operator<<(fb::math::LatexOStreamRef r, const fb::math::Matrix<M, N, T>& m)
{
    r << "\\begin{pmatrix}\n";
    for (int i = 0; i < M; ++i) {
        r << "\t";
        for (int j = 0; j < N; ++j)
            r << m[i, j] << (j != N - 1 ? " & " : "");
        r << (i != M - 1 ? " \\\\\n" : "\n");
    }
    r << "\\end{pmatrix}\n";
    return r;
}