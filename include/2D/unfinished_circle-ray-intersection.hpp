// Created by felix on 11/13/22, 2:24 PM.
#pragma once

#include <2D/ray.hpp>
#include <2D/circle.hpp>
#include <ostream_interop.hpp>

namespace fbmath {
//template <std::floating_point ParamType>
///// \tparam ParamType
///// \param c center point of circle
///// \param radius radius of circle
///// \param p origin point of ray
///// \param r direction vector of ray
///// \return parameter into the ray for intersection point
//constexpr std::optional<std::pair<ParamType, ParamType>> getIntersectionParams(
//    const Vec2<ParamType>& c, const ParamType& radius,
//    const Vec2<ParamType>& p, const Vec2<ParamType>& r
//)
//{
//    using T = ParamType;
//    constexpr T two = ParamType(2);
//    constexpr T four = ParamType(4);
//
//    const T twordotc = two * dotProduct<ParamType>(r, c);
//    const T fourrdotcsq = twordotc * twordotc;
//    const T tworssq = two * r.sizeSquared();
//    const T fourrssq = two * tworssq;
//    const T pcssq = (p + c).sizeSquared();
//    const T fourpdotc = four * dotProduct<ParamType>(p, c);
//    const T radiussq = radius * radius;
//
//    const T d = fourrdotcsq + fourrssq * (fourpdotc + radiussq - pcssq);
//    if (d < 0) return std::nullopt;
//
//    /* at least one point */
//    const ParamType minusb = twordotc;
//    const ParamType twoa = tworssq;
//
//    if (d == 0) [[unlikely]] {
//        const ParamType val = minusb / twoa;
//        return std::make_pair(val, val);
//    } else [[likely]] {
//        const ParamType v1 = (minusb + std::sqrt(d)) / twoa;
//        const ParamType v2 = (minusb - std::sqrt(d)) / twoa;
//        return std::make_pair(v1, v2);
//    }
//}
//
//
//namespace impl {
//template <Number N, Number O, Number R>
//requires std::floating_point<MorePreciseType<N, O>>
//struct IntersectionTypeS<Ray<N>, Circle<O, R>> {
//    using Num = MorePreciseType<N, O>;
//    using Type = std::optional<std::pair<Vec2<Num>, Vec2<Num>>>;
//};
//
//template <Number N, Number O, Number R>
//struct IntersectionTypeS<Ray<N>, Circle<O, R>> {
//    using Type = std::optional<std::pair<V2d, V2d>>;
//};
//}
//
//template <Number RayN, Number CN, Number RN>
//constexpr IntersectionType<Ray<RayN>, Circle<CN, RN>> intersection(
//    const Ray<RayN>& ray, const Circle<CN, RN>& circle)
//{
//    using InType = IntersectionType<Ray<RayN>, Circle<CN, RN>>;
//    using ParamType = InType::value_type::first_type::Type;
//
//    const auto optparams = getIntersectionParams<ParamType>(
//        Vec2<ParamType>::from(circle.c),
//        static_cast<ParamType>(circle.r),
//        Vec2<ParamType>::from(ray.org),
//        Vec2<ParamType>::from(ray.dir)
//    );
//    if (!optparams) return std::nullopt;
//    std::cout << ray << ", " << circle << '\n';
//    std::cout << "Params: " << optparams->first << ", " << optparams->second << '\n';
//    return std::make_pair(
//        ray.org + optparams->first * ray.dir,// ray.get(optparams->first),
//        ray.org + optparams->second * ray.dir// ray.get(optparams->second)
//    );
//}


}