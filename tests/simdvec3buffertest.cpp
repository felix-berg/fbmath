// Created by felix on 10/20/23, 12:59 PM

#include <fbtt.hpp>
#include "fbmath/simd/primitives/vec3s.hpp"
#include "fbmath/primitives/vec3.hpp"
#include "fbmath/ostream_interop.hpp"

float randFloat01()
{
    return (rand() / float(RAND_MAX)) * 2.0f - 1.0f;
}

int main()
{
    using namespace fbtt;
    using namespace fb::math;
    using namespace simd;

    using V3fBuf = Vec3Buffer<float>;
    MultiTest<std::vector<V3f>, V3fBuf> st { "Test of simd vec3" };

    static constexpr
        size_t numChunks = 8;
    static constexpr
        size_t numVecs = V3fBuf::SimdType::size() * numChunks;

    srand(clock());

    st.addConstructor("Constructor with random vectors", [](auto*& vec, auto*& buffer) {
        vec = new std::vector<V3f> {};
        buffer = new V3fBuf {};

        buffer->resize(numChunks);

        for (size_t i = 0; i < numVecs; ++i) {
            vec->push_back({
                randFloat01(),
                randFloat01(),
                randFloat01()
            });
            (*buffer)[i] = vec->back();
        }
    });

    st.addTest("Loading of simd registers, checking equality with source",
        [](auto& vectors, auto& buffer) {
        for (size_t i = 0; i < numChunks; ++i) {
            V3fBuf::SimdType regx;
            buffer.loadx(regx, i);

            for (size_t j = 0; j < decltype(regx)::size(); ++j) {
                float vx = regx[j];
                assertEquals(vx, vectors.at(i * decltype(regx)::size() + j).x);
            }

            V3fBuf::SimdType regy;
            buffer.loady(regy, i);

            for (size_t j = 0; j < decltype(regy)::size(); ++j) {
                float vy = regy[j];
                assertEquals(vy, vectors.at(i * decltype(regy)::size() + j).y);
            }

            V3fBuf::SimdType regz;
            buffer.loadz(regz, i);

            for (size_t j = 0; j < decltype(regz)::size(); ++j) {
                float vz = regz[j];
                assertEquals(vz, vectors.at(i * decltype(regz)::size() + j).z);
            }
        }
    });

    st.addTest("Load/store", [](auto& vectors, auto& buffer) {
        V3fBuf clone;
        clone.resize(numChunks);

        V3fBuf::SimdType reg;
        for (int i = 0; i < numChunks; ++i) {
            buffer.loadx(reg, i);
            clone.storex(reg, i);
            buffer.loady(reg, i);
            clone.storey(reg, i);
            buffer.loadz(reg, i);
            clone.storez(reg, i);
        }

        for (int i = 0; i < numVecs; ++i) {
            assertEquals(buffer.get(i), clone.get(i));
        }
    });

    st.addTest("Add", [](auto& vectors, auto& buffer) {
        auto vectors2 = vectors;
        for (size_t i = 0; i < vectors2.size(); ++i)
            vectors2[i] = randFloat01() * vectors[i];

        V3fBuf buffer2 = buffer;
        for (size_t i = 0; i < vectors2.size(); ++i)
            buffer2[i] = vectors2[i];

        add(buffer, buffer, buffer2);

        for (int i = 0; i < vectors.size(); ++i)
            vectors[i] += vectors2[i];

        for (int i = 0; i < vectors.size(); ++i)
            assertEquals(buffer.get(i), vectors[i]);
    });



    st.run();
    std::cout << st;
    return getErrorCode(st.getResults());
}