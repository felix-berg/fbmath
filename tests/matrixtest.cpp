// Created by felix on 10/16/23, 4:53 PM

#include <fbtt.hpp>
#include <fbmath/matrix.hpp>
#include <fbmath/ostream_interop.hpp>

using namespace fb::math;

template <int M, int N, typename T>
auto createMatrices()
{
    Matrix<M, N, T> m1;
    Matrix<M, N, T> m2;
    Matrix<M, N, T> m3;

    for (int i = 0; i < M * N; ++i) {
        *(m1.begin() + i) = i;
        *(m2.begin() + i) = - 2 * i;
        *(m3.begin() + i) = 0;
    }
    return std::make_tuple(m1, m2, m3);
}

int main()
{
    using namespace fbtt;
    using namespace fb::math;

    MultiTest mt {
        "Test of matrix class"
    };

    mt.addTest("Construction of various matrices", [] {
        Matrix<2, 2, int> m1 {
            { 1, 2 },
            { 3, 4 }
        };

        int a[2][2] {
            { 1, 2 },
            { 3, 4 }
        };

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; j++)
                assertEquals(a[i][j], m1[i, j]);

        Matrix<5, 3, int> m2 {
            { 1, 2, 3 },
            { -4, -5, -6 },
            { 7, 8, 9 },
            { -10, -11, -12 },
            { 13, 14, 15 }
        };

        int b[5][3] {
            { 1, 2, 3 },
            { -4, -5, -6 },
            { 7, 8, 9 },
            { -10, -11, -12 },
            { 13, 14, 15 }
        };

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                assertEquals(b[i][j], m2[i, j]);

        int c[2][4] { { 0 } };
        Matrix<2, 4, int> m3;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 4; ++j)
                assertEquals(c[i][j], m3[i, j]);

        // fails static assertion
//        Matrix<-3, -2, float> mf {
//            { 1, 2, },
//            { 4, 5, },
//            { 7, 8, }
//        };
    });

    mt.addTest("Addition into", [] {
        auto [m1, m2, m3] = createMatrices<3, 4, int>();
        m3 += m1;
        assertEquals(m3, m1);

        m3 += m2;
        m3 += m2;
        m3 += m1;
        m1 += m2;
        m1 += m1;
        assertEquals(m1, m3);
    });

    mt.addTest("Subtraction into", [] {
        auto [m1, m2, m3] = createMatrices<51, 42, float>();
        m3 -= m1;
        m3 -= m1;
        assertEquals(m3, m2);
        m3 -= m3;
        m1 -= m1;
        assertEquals(m3, m1);
    });

    mt.addTest("Scalar multiplication/division", [] {
        auto [m1, m2, m3] = createMatrices<412, 132, double>();
        m1 *= -2.;
        assertEquals(m1, m2);

        m1 /= -0.5;
        m2 *= -2;
        assertEquals(m1, m2);

        m1 *= 0;
        assertEquals(m1, Matrix<412, 132, double>{});
    });

    mt.addTest("Matrix multiplication using multiplyInto", [] {
        Matrix<4, 3, short> m1;
        Matrix<3, 6, int> m2;
        Matrix<4, 6, long long> r;
        multiplyInto(r, m1, m2);
        assertEquals(r, decltype(r){});

        int i{};
        for (short& x: m1)
            x = i++;
        for (int& y: m2)
            y = 2 * i++;

        Matrix<4, 6, long long> expected {
            { 132,  138,  144,  150,  156,  162 },
            { 456,  480,  504,  528,  552,  576 },
            { 780,  822,  864,  906,  948,  990 },
            { 1104, 1164, 1224, 1284, 1344, 1404 },
        };

        multiplyInto(r, m1, m2);
        assertEquals(expected, r);
    });

    mt.addTest("Matrix multiplication using operator*", [] {
        Matrix<4, 3, short> m1;
        Matrix<3, 6, int> m2;

        assertEquals(m1 * m2, Matrix<4, 6, int>{});

        int i{};
        for (short& x: m1)
            x = i++;
        for (int& y: m2)
            y = 2 * i++;

        Matrix<4, 6, int> expected {
            { 132,  138,  144,  150,  156,  162 },
            { 456,  480,  504,  528,  552,  576 },
            { 780,  822,  864,  906,  948,  990 },
            { 1104, 1164, 1224, 1284, 1344, 1404 },
        };

        assertEquals(expected, m1 * m2);
    });

    mt.addTest("Identity matrix", [] {
        Matrix<3, 3, int> m1;
        for (int& x: m1)
            x = rand();
        assertEquals(m1, m1 * decltype(m1)::identity());

        Matrix<56, 56, double> m2;
        for (double& x: m2)
            x = rand();
        assertEquals(m2, m2 * Matrix<56,56,double>::identity());
    });

    mt.addTest("transposeInto", [] {
        Matrix<4, 3, double> m;
        int i = 1;
        for (double& d: m)
            d = i++;
        Matrix<3, 4, float> r;
        transposeInto(r, m);
        assertEquals(r, Matrix<3, 4, float> {
            { 1, 4, 7, 10 },
            { 2, 5, 8, 11 },
            { 3, 6, 9, 12 }
        });
    });

    mt.addTest("Transposing matrix", [] {
        Matrix<40, 17, int> m;
        for (int& x: m)
            x = rand();
        Matrix<17,40, int> mt;
        transposeInto(mt, m);
        assertEquals(m.transposed(), mt);
    });

    mt.addTest("det", [] {
        Matrix<2, 2, int> m {
            { 1, 2 },
            { 3, 4 }
        };
        assertEquals(m.determinant(), -2);
    });

    mt.addTest("Conversion to vec2, vec3", [] {
        Matrix<2, 1, float> m1 {
            { 3.1423f },
            { 2.132f }
        };

        assertEquals(Vec2<float>(m1), Vec2<float> {
            3.1423f, 2.132f
        });

        Matrix<3, 1, long long> m2 {
            { 1389012L },
            { 2L << 31 },
            { 313      }
        };

        assertEquals(Vec3<long long>(m2), Vec3<long long> {
            1389012L,
            2L << 31,
            313
        });

    });

    mt.run();
    std::cout << mt;
    return getErrorCode(mt.getResults());
}