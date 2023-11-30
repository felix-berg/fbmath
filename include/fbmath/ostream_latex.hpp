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

LatexOStreamRef operator<<(std::ostream& os, decltype(latexFormat)&)
{
    return LatexOStreamRef { os };
}

template <typename N>
LatexOStreamRef operator<<(LatexOStreamRef r, const Vec2<N>& v) noexcept
{
    r.os << "\begin{pmatrix} \n"
         << v.x << "\\ " << v.y
         << "\n\\end{pmatrix}";
    return r;
}

template <typename N>
LatexOStreamRef operator<<(LatexOStreamRef r, const Vec3<N>& v) noexcept
{
    r.os << "\begin{pmatrix} \n"
         << v.x << "\\ " << v.y << "\\ " << v.z
         << "\n\\end{pmatrix}";
    return r;
}

template <int M, int N, typename T>
LatexOStreamRef operator<<(LatexOStreamRef r, const Matrix<M, N, T>& m)
{
    r.os << "\\begin{pmatrix}\n";
    for (int i = 0; i < M; ++i) {
        r.os << "\t";
        for (int j = 0; j < N; ++j)
            r.os << m[i, j] << (j != N - 1 ? " & " : "");
        r.os << (i != M - 1 ? " \\\\\n" : "\n");
    }
    r.os << "\\end{pmatrix}\n";
    return r;
}

}}