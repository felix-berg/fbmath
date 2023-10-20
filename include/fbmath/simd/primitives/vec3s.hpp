// Created by felix on 10/20/23, 12:57 PM
#pragma once

#include <array>
#include <cassert>

#include "fbmath/number.hpp"
#include "fbmath/primitives/primitive-predeclaration.hpp"
#include "fbmath/simd/def.hpp"


namespace fb { namespace math { namespace simd {

template <Number N>
struct Vec3Buffer {
    using SimdType = stdx::native_simd<N>;

    // aligned as of c++17
    // https://stackoverflow.com/questions/8456236/how-is-a-vectors-data-aligned
    std::vector<N> x;
    std::vector<N> y;
    std::vector<N> z;

    /** resize to given number of simd vectors */
    void resize(size_t numSimdVectors) noexcept
    {
        x.resize(numSimdVectors * SimdType::size());
        y.resize(numSimdVectors * SimdType::size());
        z.resize(numSimdVectors * SimdType::size());
    }

    size_t numVecs() const noexcept {
        return x.size();
    }

    Vec3<N> get(size_t i) const noexcept
    {
        return { x[i], y[i], z[i] };
    }

    size_t numSimdChunks() const noexcept {
        return numVecs() / SimdType::size();
    }

    void loadx(SimdType& vec, size_t chunkIndex) const noexcept {
        vec.copy_from(x.data() + chunkIndex * SimdType::size(),
            stdx::vector_aligned);
    }

    void loady(SimdType& vec, size_t chunkIndex) const noexcept {
        vec.copy_from(y.data() + chunkIndex * SimdType::size(),
            stdx::vector_aligned);
    }

    void loadz(SimdType& vec, size_t chunkIndex) const noexcept {
        vec.copy_from(z.data() + chunkIndex * SimdType::size(),
            stdx::vector_aligned);
    }

    void storex(const SimdType& vec, size_t chunkIndex) noexcept {
        vec.copy_to(x.data() + chunkIndex * SimdType::size(),
            stdx::vector_aligned);
    }

    void storey(const SimdType& vec, size_t chunkIndex) noexcept {
        vec.copy_to(y.data() + chunkIndex * SimdType::size(),
            stdx::vector_aligned);
    }

    void storez(const SimdType& vec, size_t chunkIndex) noexcept {
        vec.copy_to(z.data() + chunkIndex * SimdType::size(),
            stdx::vector_aligned);
    }

private:
    struct ConstElementReference {
        ConstElementReference(Vec3Buffer& parent, size_t elm)
            : buffer { parent }, idx { elm } { }

        operator Vec3<N>() const noexcept
        {
            return {
                buffer.x[index],
                buffer.y[index],
                buffer.z[index],
            };
        }

    protected:
        Vec3Buffer& buffer;
        size_t idx;
    };

    struct ElementReference : public ConstElementReference {
        ElementReference(Vec3Buffer& parent, size_t elm)
            : ConstElementReference { parent, elm } { }

        ElementReference& operator=(const Vec3<N>& vec) noexcept
        {
            ConstElementReference::buffer.x[ConstElementReference::idx] = vec.x;
            ConstElementReference::buffer.y[ConstElementReference::idx] = vec.y;
            ConstElementReference::buffer.z[ConstElementReference::idx] = vec.z;
            return *this;
        }
    };

public:
    ElementReference operator[](size_t i) noexcept
    {
        return ElementReference(*this, i);
    }

    ConstElementReference operator[](size_t i) const noexcept
    {
        return ConstElementReference(*this, i);
    }
};

template <Number N>
void add(Vec3Buffer<N>& result, const Vec3Buffer<N>& a, const Vec3Buffer<N>& b)
    noexcept
{
    assert(a.numSimdChunks() == b.numSimdChunks());

    Vec3Buffer<float>::SimdType a_, b_;
    for (size_t i = 0; i < a.numSimdChunks(); ++i) {
        a.loadx(a_, i);
        b.loadx(b_, i);
        a_ += b_;
        result.storex(a_, i);

        a.loady(a_, i);
        b.loady(b_, i);
        a_ += b_;
        result.storey(a_, i);

        a.loadz(a_, i);
        b.loadz(b_, i);
        a_ += b_;
        result.storez(a_, i);
    }
}

}}}