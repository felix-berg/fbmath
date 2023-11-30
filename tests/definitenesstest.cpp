// Created by felix on 11/30/23, 9:13 PM
#include "fbmath.hpp"
#include "fbtt.hpp"

int main(int argc, char** argv)
{
    using namespace fbtt;
    using namespace fb::math;

    MultiTest dt { "Test of diagonalize/definiteness" };

    dt.addTest("2x2 matrices positive definiteness", [] {
        Matrix<2, 2, double> mat1_2x2 = Matrix<2, 2, int64_t> { {16, 1}, {1, 51}
        }.convertTo<double>(); // true
        assertTrue(mat1_2x2.symmetric(), "mat1_2x2 is not symmetric\n");
        diagonalize(mat1_2x2);
        assertTrue(positiveDiagonal(mat1_2x2), "diagonalized mat1_2x2 is not correct");
        assertTrue(positiveDefinite(mat1_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat2_2x2 = Matrix<2, 2, int64_t> { {91, 3}, {3, 60}
        }.convertTo<double>(); // true
        assertTrue(mat2_2x2.symmetric(), "mat2_2x2 is not symmetric\n");
        diagonalize(mat2_2x2);
        assertTrue(positiveDiagonal(mat2_2x2), "diagonalized mat2_2x2 is not correct");
        assertTrue(positiveDefinite(mat2_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat3_2x2 = Matrix<2, 2, int64_t> { {89, 81}, {81, 89}
        }.convertTo<double>(); // true
        assertTrue(mat3_2x2.symmetric(), "mat3_2x2 is not symmetric\n");
        diagonalize(mat3_2x2);
        assertTrue(positiveDiagonal(mat3_2x2), "diagonalized mat3_2x2 is not correct");
        assertTrue(positiveDefinite(mat3_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat4_2x2 = Matrix<2, 2, int64_t> { {45, 2}, {2, 89}
        }.convertTo<double>(); // true
        assertTrue(mat4_2x2.symmetric(), "mat4_2x2 is not symmetric\n");
        diagonalize(mat4_2x2);
        assertTrue(positiveDiagonal(mat4_2x2), "diagonalized mat4_2x2 is not correct");
        assertTrue(positiveDefinite(mat4_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat5_2x2 = Matrix<2, 2, int64_t> { {87, -19}, {-19, 56}
        }.convertTo<double>(); // true
        assertTrue(mat5_2x2.symmetric(), "mat5_2x2 is not symmetric\n");
        diagonalize(mat5_2x2);
        assertTrue(positiveDiagonal(mat5_2x2), "diagonalized mat5_2x2 is not correct");
        assertTrue(positiveDefinite(mat5_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat6_2x2 = Matrix<2, 2, int64_t> { {-86, -46}, {-46, -12}
        }.convertTo<double>(); // false
        assertTrue(mat6_2x2.symmetric(), "mat6_2x2 is not symmetric\n");
        diagonalize(mat6_2x2);
        assertTrue(mat6_2x2.diagonal(), "mat6_2x2 was not diagonal");
        assertFalse(positiveDiagonal(mat6_2x2), "diagonalized mat6_2x2 is not correct");
        assertFalse(positiveDefinite(mat6_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat7_2x2 = Matrix<2, 2, int64_t> { {-30, -53}, {-53, 28}
        }.convertTo<double>(); // false
        assertTrue(mat7_2x2.symmetric(), "mat7_2x2 is not symmetric\n");
        diagonalize(mat7_2x2);
        assertTrue(mat7_2x2.diagonal(), "mat7_2x2 was not diagonal");
        assertFalse(positiveDiagonal(mat7_2x2), "diagonalized mat7_2x2 is not correct");
        assertFalse(positiveDefinite(mat7_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat8_2x2 = Matrix<2, 2, int64_t> { {35, 0}, {0, -20}
        }.convertTo<double>(); // false
        assertTrue(mat8_2x2.symmetric(), "mat8_2x2 is not symmetric\n");
        diagonalize(mat8_2x2);
        assertTrue(mat8_2x2.diagonal(), "mat8_2x2 was not diagonal");
        assertFalse(positiveDiagonal(mat8_2x2), "diagonalized mat8_2x2 is not correct");
        assertFalse(positiveDefinite(mat8_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat9_2x2 = Matrix<2, 2, int64_t> { {35, 62}, {62, -68}
        }.convertTo<double>(); // false
        assertTrue(mat9_2x2.symmetric(), "mat9_2x2 is not symmetric\n");
        diagonalize(mat9_2x2);
        assertTrue(mat9_2x2.diagonal(), "mat9_2x2 was not diagonal");
        assertFalse(positiveDiagonal(mat9_2x2), "diagonalized mat9_2x2 is not correct");
        assertFalse(positiveDefinite(mat9_2x2), "positiveDefinite is not correct");

        Matrix<2, 2, double> mat10_2x2 = Matrix<2, 2, int64_t> { {22, -78}, {-78, -73}
        }.convertTo<double>(); // false
        assertTrue(mat10_2x2.symmetric(), "mat10_2x2 is not symmetric\n");
        diagonalize(mat10_2x2);
        assertTrue(mat10_2x2.diagonal(), "mat10_2x2 was not diagonal");
        assertFalse(positiveDiagonal(mat10_2x2), "diagonalized mat10_2x2 is not correct");
        assertFalse(positiveDefinite(mat10_2x2), "positiveDefinite is not correct");

    });

    dt.addTest("3x3 matrices positive definiteness", [] {
        Matrix<3, 3, double> mat1_3x3 = Matrix<3, 3, int64_t> { {11, -5, 30}, {-5, 45, 4}, {30, 4, 93}
        }.convertTo<double>(); // true
        assertTrue(mat1_3x3.symmetric(), "mat1_3x3 is not symmetric\n");
        diagonalize(mat1_3x3);
        assertTrue(positiveDiagonal(mat1_3x3), "diagonalized mat1_3x3 is not correct");
        assertTrue(positiveDefinite(mat1_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat2_3x3 = Matrix<3, 3, int64_t> { {79, 36, -55}, {36, 43, -18}, {-55, -18, 80}
        }.convertTo<double>(); // true
        assertTrue(mat2_3x3.symmetric(), "mat2_3x3 is not symmetric\n");
        diagonalize(mat2_3x3);
        assertTrue(positiveDiagonal(mat2_3x3), "diagonalized mat2_3x3 is not correct");
        assertTrue(positiveDefinite(mat2_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat3_3x3 = Matrix<3, 3, int64_t> { {69, -19, -10}, {-19, 21, 10}, {-10, 10, 64}
        }.convertTo<double>(); // true
        assertTrue(mat3_3x3.symmetric(), "mat3_3x3 is not symmetric\n");
        diagonalize(mat3_3x3);
        assertTrue(positiveDiagonal(mat3_3x3), "diagonalized mat3_3x3 is not correct");
        assertTrue(positiveDefinite(mat3_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat4_3x3 = Matrix<3, 3, int64_t> { {56, -40, 10}, {-40, 72, 11}, {10, 11, 14}
        }.convertTo<double>(); // true
        assertTrue(mat4_3x3.symmetric(), "mat4_3x3 is not symmetric\n");
        diagonalize(mat4_3x3);
        assertTrue(positiveDiagonal(mat4_3x3), "diagonalized mat4_3x3 is not correct");
        assertTrue(positiveDefinite(mat4_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat5_3x3 = Matrix<3, 3, int64_t> { {95, 7, -47}, {7, 91, -18}, {-47, -18, 44}
        }.convertTo<double>(); // true
        assertTrue(mat5_3x3.symmetric(), "mat5_3x3 is not symmetric\n");
        diagonalize(mat5_3x3);
        assertTrue(positiveDiagonal(mat5_3x3), "diagonalized mat5_3x3 is not correct");
        assertTrue(positiveDefinite(mat5_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat6_3x3 = Matrix<3, 3, int64_t> { {37, -31, 2}, {-31, 19, 20}, {2, 20, 74}
        }.convertTo<double>(); // false
        assertTrue(mat6_3x3.symmetric(), "mat6_3x3 is not symmetric\n");
        diagonalize(mat6_3x3);
        assertTrue(mat6_3x3.diagonal(), "mat6_3x3 was not diagonal");
        assertFalse(positiveDiagonal(mat6_3x3), "diagonalized mat6_3x3 is not correct");
        assertFalse(positiveDefinite(mat6_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat7_3x3 = Matrix<3, 3, int64_t> { {-72, 43, 58}, {43, -94, -70}, {58, -70, 33}
        }.convertTo<double>(); // false
        assertTrue(mat7_3x3.symmetric(), "mat7_3x3 is not symmetric\n");
        diagonalize(mat7_3x3);
        assertTrue(mat7_3x3.diagonal(), "mat7_3x3 was not diagonal");
        assertFalse(positiveDiagonal(mat7_3x3), "diagonalized mat7_3x3 is not correct");
        assertFalse(positiveDefinite(mat7_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat8_3x3 = Matrix<3, 3, int64_t> { {10, 28, 66}, {28, -43, -74}, {66, -74, -97}
        }.convertTo<double>(); // false
        assertTrue(mat8_3x3.symmetric(), "mat8_3x3 is not symmetric\n");
        diagonalize(mat8_3x3);
        assertTrue(mat8_3x3.diagonal(), "mat8_3x3 was not diagonal");
        assertFalse(positiveDiagonal(mat8_3x3), "diagonalized mat8_3x3 is not correct");
        assertFalse(positiveDefinite(mat8_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat9_3x3 = Matrix<3, 3, int64_t> { {-2, -23, -3}, {-23, 18, -49}, {-3, -49, 15}
        }.convertTo<double>(); // false
        assertTrue(mat9_3x3.symmetric(), "mat9_3x3 is not symmetric\n");
        diagonalize(mat9_3x3);
        assertTrue(mat9_3x3.diagonal(), "mat9_3x3 was not diagonal");
        assertFalse(positiveDiagonal(mat9_3x3), "diagonalized mat9_3x3 is not correct");
        assertFalse(positiveDefinite(mat9_3x3), "positiveDefinite is not correct");

        Matrix<3, 3, double> mat10_3x3 = Matrix<3, 3, int64_t> { {-69, 6, 84}, {6, -79, -47}, {84, -47, 25}
        }.convertTo<double>(); // false
        assertTrue(mat10_3x3.symmetric(), "mat10_3x3 is not symmetric\n");
        diagonalize(mat10_3x3);
        assertTrue(mat10_3x3.diagonal(), "mat10_3x3 was not diagonal");
        assertFalse(positiveDiagonal(mat10_3x3), "diagonalized mat10_3x3 is not correct");
        assertFalse(positiveDefinite(mat10_3x3), "positiveDefinite is not correct");

    });

    dt.addTest("4x4 matrices positive definiteness", [] {
        Matrix<4, 4, double> mat1_4x4 = Matrix<4, 4, int64_t> { {91, 34, 57, -24}, {34, 78, 41, -63}, {57, 41, 62, -19}, {-24, -63, -19, 72}
        }.convertTo<double>(); // true
        assertTrue(mat1_4x4.symmetric(), "mat1_4x4 is not symmetric\n");
        diagonalize(mat1_4x4);
        assertTrue(positiveDiagonal(mat1_4x4), "diagonalized mat1_4x4 is not correct");
        assertTrue(positiveDefinite(mat1_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat2_4x4 = Matrix<4, 4, int64_t> { {66, -8, -5, 38}, {-8, 72, 41, -1}, {-5, 41, 83, 6}, {38, -1, 6, 50}
        }.convertTo<double>(); // true
        assertTrue(mat2_4x4.symmetric(), "mat2_4x4 is not symmetric\n");
        diagonalize(mat2_4x4);
        assertTrue(positiveDiagonal(mat2_4x4), "diagonalized mat2_4x4 is not correct");
        assertTrue(positiveDefinite(mat2_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat3_4x4 = Matrix<4, 4, int64_t> { {84, 21, -5, -29}, {21, 97, -40, -13}, {-5, -40, 54, 24}, {-29, -13, 24, 33}
        }.convertTo<double>(); // true
        assertTrue(mat3_4x4.symmetric(), "mat3_4x4 is not symmetric\n");
        diagonalize(mat3_4x4);
        assertTrue(positiveDiagonal(mat3_4x4), "diagonalized mat3_4x4 is not correct");
        assertTrue(positiveDefinite(mat3_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat4_4x4 = Matrix<4, 4, int64_t> { {60, 5, -16, 47}, {5, 88, 3, -1}, {-16, 3, 81, 24}, {47, -1, 24, 83}
        }.convertTo<double>(); // true
        assertTrue(mat4_4x4.symmetric(), "mat4_4x4 is not symmetric\n");
        diagonalize(mat4_4x4);
        assertTrue(positiveDiagonal(mat4_4x4), "diagonalized mat4_4x4 is not correct");
        assertTrue(positiveDefinite(mat4_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat5_4x4 = Matrix<4, 4, int64_t> { {90, 48, 2, -11}, {48, 92, -45, 36}, {2, -45, 78, -47}, {-11, 36, -47, 50}
        }.convertTo<double>(); // true
        assertTrue(mat5_4x4.symmetric(), "mat5_4x4 is not symmetric\n");
        diagonalize(mat5_4x4);
        assertTrue(positiveDiagonal(mat5_4x4), "diagonalized mat5_4x4 is not correct");
        assertTrue(positiveDefinite(mat5_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat6_4x4 = Matrix<4, 4, int64_t> { {-11, -28, -27, 64}, {-28, 10, -6, -15}, {-27, -6, -34, 11}, {64, -15, 11, -85}
        }.convertTo<double>(); // false
        assertTrue(mat6_4x4.symmetric(), "mat6_4x4 is not symmetric\n");
        diagonalize(mat6_4x4);
        assertTrue(mat6_4x4.diagonal(), "mat6_4x4 was not diagonal");
        assertFalse(positiveDiagonal(mat6_4x4), "diagonalized mat6_4x4 is not correct");
        assertFalse(positiveDefinite(mat6_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat7_4x4 = Matrix<4, 4, int64_t> { {-57, -67, 0, -20}, {-67, 46, -31, 15}, {0, -31, -47, -63}, {-20, 15, -63, -69}
        }.convertTo<double>(); // false
        assertTrue(mat7_4x4.symmetric(), "mat7_4x4 is not symmetric\n");
        diagonalize(mat7_4x4);
        assertTrue(mat7_4x4.diagonal(), "mat7_4x4 was not diagonal");
        assertFalse(positiveDiagonal(mat7_4x4), "diagonalized mat7_4x4 is not correct");
        assertFalse(positiveDefinite(mat7_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat8_4x4 = Matrix<4, 4, int64_t> { {-60, -30, 19, -37}, {-30, 25, -23, 27}, {19, -23, 99, -16}, {-37, 27, -16, -79}
        }.convertTo<double>(); // false
        assertTrue(mat8_4x4.symmetric(), "mat8_4x4 is not symmetric\n");
        diagonalize(mat8_4x4);
        assertTrue(mat8_4x4.diagonal(), "mat8_4x4 was not diagonal");
        assertFalse(positiveDiagonal(mat8_4x4), "diagonalized mat8_4x4 is not correct");
        assertFalse(positiveDefinite(mat8_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat9_4x4 = Matrix<4, 4, int64_t> { {-81, -40, -11, -2}, {-40, -51, -67, -51}, {-11, -67, -13, 3}, {-2, -51, 3, -22}
        }.convertTo<double>(); // false
        assertTrue(mat9_4x4.symmetric(), "mat9_4x4 is not symmetric\n");
        diagonalize(mat9_4x4);
        assertTrue(mat9_4x4.diagonal(), "mat9_4x4 was not diagonal");
        assertFalse(positiveDiagonal(mat9_4x4), "diagonalized mat9_4x4 is not correct");
        assertFalse(positiveDefinite(mat9_4x4), "positiveDefinite is not correct");

        Matrix<4, 4, double> mat10_4x4 = Matrix<4, 4, int64_t> { {-64, -21, -29, -24}, {-21, -16, -7, 23}, {-29, -7, -14, 30}, {-24, 23, 30, -66}
        }.convertTo<double>(); // false
        assertTrue(mat10_4x4.symmetric(), "mat10_4x4 is not symmetric\n");
        diagonalize(mat10_4x4);
        assertTrue(mat10_4x4.diagonal(), "mat10_4x4 was not diagonal");
        assertFalse(positiveDiagonal(mat10_4x4), "diagonalized mat10_4x4 is not correct");
        assertFalse(positiveDefinite(mat10_4x4), "positiveDefinite is not correct");

    });

    dt.addTest("2x2 matrices positive semidefinite", [] {
        Matrix<2, 2, double> mat1_2x2 = Matrix<2, 2, int64_t> {{ {16, 1}, {1, 51}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat1_2x2.symmetric(), "mat1_2x2 is not symmetric");
        diagonalize(mat1_2x2);
        assertTrue(mat1_2x2.diagonal(), "mat1_2x2 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat1_2x2), "mat1_2x2 was incorrect");
        assertTrue(positiveSemiDefinite(mat1_2x2), "mat1_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat2_2x2 = Matrix<2, 2, int64_t> {{ {91, 3}, {3, 60}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat2_2x2.symmetric(), "mat2_2x2 is not symmetric");
        diagonalize(mat2_2x2);
        assertTrue(mat2_2x2.diagonal(), "mat2_2x2 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat2_2x2), "mat2_2x2 was incorrect");
        assertTrue(positiveSemiDefinite(mat2_2x2), "mat2_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat3_2x2 = Matrix<2, 2, int64_t> {{ {89, 81}, {81, 89}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat3_2x2.symmetric(), "mat3_2x2 is not symmetric");
        diagonalize(mat3_2x2);
        assertTrue(mat3_2x2.diagonal(), "mat3_2x2 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat3_2x2), "mat3_2x2 was incorrect");
        assertTrue(positiveSemiDefinite(mat3_2x2), "mat3_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat4_2x2 = Matrix<2, 2, int64_t> {{ {45, 2}, {2, 89}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat4_2x2.symmetric(), "mat4_2x2 is not symmetric");
        diagonalize(mat4_2x2);
        assertTrue(mat4_2x2.diagonal(), "mat4_2x2 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat4_2x2), "mat4_2x2 was incorrect");
        assertTrue(positiveSemiDefinite(mat4_2x2), "mat4_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat5_2x2 = Matrix<2, 2, int64_t> {{ {87, -19}, {-19, 56}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat5_2x2.symmetric(), "mat5_2x2 is not symmetric");
        diagonalize(mat5_2x2);
        assertTrue(mat5_2x2.diagonal(), "mat5_2x2 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat5_2x2), "mat5_2x2 was incorrect");
        assertTrue(positiveSemiDefinite(mat5_2x2), "mat5_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat6_2x2 = Matrix<2, 2, int64_t> {{ {-86, -46}, {-46, -12}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat6_2x2.symmetric(), "mat6_2x2 is not symmetric");
        diagonalize(mat6_2x2);
        assertTrue(mat6_2x2.diagonal(), "mat6_2x2 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat6_2x2), "mat6_2x2 was incorrect");
        assertFalse(positiveSemiDefinite(mat6_2x2), "mat6_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat7_2x2 = Matrix<2, 2, int64_t> {{ {-30, -53}, {-53, 28}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat7_2x2.symmetric(), "mat7_2x2 is not symmetric");
        diagonalize(mat7_2x2);
        assertTrue(mat7_2x2.diagonal(), "mat7_2x2 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat7_2x2), "mat7_2x2 was incorrect");
        assertFalse(positiveSemiDefinite(mat7_2x2), "mat7_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat8_2x2 = Matrix<2, 2, int64_t> {{ {35, 0}, {0, -20}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat8_2x2.symmetric(), "mat8_2x2 is not symmetric");
        diagonalize(mat8_2x2);
        assertTrue(mat8_2x2.diagonal(), "mat8_2x2 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat8_2x2), "mat8_2x2 was incorrect");
        assertFalse(positiveSemiDefinite(mat8_2x2), "mat8_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat9_2x2 = Matrix<2, 2, int64_t> {{ {35, 62}, {62, -68}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat9_2x2.symmetric(), "mat9_2x2 is not symmetric");
        diagonalize(mat9_2x2);
        assertTrue(mat9_2x2.diagonal(), "mat9_2x2 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat9_2x2), "mat9_2x2 was incorrect");
        assertFalse(positiveSemiDefinite(mat9_2x2), "mat9_2x2 positiveSemiDefinite was incorrect");

        Matrix<2, 2, double> mat10_2x2 = Matrix<2, 2, int64_t> {{ {22, -78}, {-78, -73}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat10_2x2.symmetric(), "mat10_2x2 is not symmetric");
        diagonalize(mat10_2x2);
        assertTrue(mat10_2x2.diagonal(), "mat10_2x2 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat10_2x2), "mat10_2x2 was incorrect");
        assertFalse(positiveSemiDefinite(mat10_2x2), "mat10_2x2 positiveSemiDefinite was incorrect");

    });

    dt.addTest("3x3 matrices positive semidefinite", [] {
        Matrix<3, 3, double> mat1_3x3 = Matrix<3, 3, int64_t> {{ {11, -5, 30}, {-5, 45, 4}, {30, 4, 93}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat1_3x3.symmetric(), "mat1_3x3 is not symmetric");
        diagonalize(mat1_3x3);
        assertTrue(mat1_3x3.diagonal(), "mat1_3x3 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat1_3x3), "mat1_3x3 was incorrect");
        assertTrue(positiveSemiDefinite(mat1_3x3), "mat1_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat2_3x3 = Matrix<3, 3, int64_t> {{ {79, 36, -55}, {36, 43, -18}, {-55, -18, 80}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat2_3x3.symmetric(), "mat2_3x3 is not symmetric");
        diagonalize(mat2_3x3);
        assertTrue(mat2_3x3.diagonal(), "mat2_3x3 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat2_3x3), "mat2_3x3 was incorrect");
        assertTrue(positiveSemiDefinite(mat2_3x3), "mat2_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat3_3x3 = Matrix<3, 3, int64_t> {{ {69, -19, -10}, {-19, 21, 10}, {-10, 10, 64}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat3_3x3.symmetric(), "mat3_3x3 is not symmetric");
        diagonalize(mat3_3x3);
        assertTrue(mat3_3x3.diagonal(), "mat3_3x3 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat3_3x3), "mat3_3x3 was incorrect");
        assertTrue(positiveSemiDefinite(mat3_3x3), "mat3_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat4_3x3 = Matrix<3, 3, int64_t> {{ {56, -40, 10}, {-40, 72, 11}, {10, 11, 14}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat4_3x3.symmetric(), "mat4_3x3 is not symmetric");
        diagonalize(mat4_3x3);
        assertTrue(mat4_3x3.diagonal(), "mat4_3x3 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat4_3x3), "mat4_3x3 was incorrect");
        assertTrue(positiveSemiDefinite(mat4_3x3), "mat4_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat5_3x3 = Matrix<3, 3, int64_t> {{ {95, 7, -47}, {7, 91, -18}, {-47, -18, 44}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat5_3x3.symmetric(), "mat5_3x3 is not symmetric");
        diagonalize(mat5_3x3);
        assertTrue(mat5_3x3.diagonal(), "mat5_3x3 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat5_3x3), "mat5_3x3 was incorrect");
        assertTrue(positiveSemiDefinite(mat5_3x3), "mat5_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat6_3x3 = Matrix<3, 3, int64_t> {{ {37, -31, 2}, {-31, 19, 20}, {2, 20, 74}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat6_3x3.symmetric(), "mat6_3x3 is not symmetric");
        diagonalize(mat6_3x3);
        assertTrue(mat6_3x3.diagonal(), "mat6_3x3 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat6_3x3), "mat6_3x3 was incorrect");
        assertFalse(positiveSemiDefinite(mat6_3x3), "mat6_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat7_3x3 = Matrix<3, 3, int64_t> {{ {-72, 43, 58}, {43, -94, -70}, {58, -70, 33}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat7_3x3.symmetric(), "mat7_3x3 is not symmetric");
        diagonalize(mat7_3x3);
        assertTrue(mat7_3x3.diagonal(), "mat7_3x3 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat7_3x3), "mat7_3x3 was incorrect");
        assertFalse(positiveSemiDefinite(mat7_3x3), "mat7_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat8_3x3 = Matrix<3, 3, int64_t> {{ {10, 28, 66}, {28, -43, -74}, {66, -74, -97}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat8_3x3.symmetric(), "mat8_3x3 is not symmetric");
        diagonalize(mat8_3x3);
        assertTrue(mat8_3x3.diagonal(), "mat8_3x3 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat8_3x3), "mat8_3x3 was incorrect");
        assertFalse(positiveSemiDefinite(mat8_3x3), "mat8_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat9_3x3 = Matrix<3, 3, int64_t> {{ {-2, -23, -3}, {-23, 18, -49}, {-3, -49, 15}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat9_3x3.symmetric(), "mat9_3x3 is not symmetric");
        diagonalize(mat9_3x3);
        assertTrue(mat9_3x3.diagonal(), "mat9_3x3 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat9_3x3), "mat9_3x3 was incorrect");
        assertFalse(positiveSemiDefinite(mat9_3x3), "mat9_3x3 positiveSemiDefinite was incorrect");

        Matrix<3, 3, double> mat10_3x3 = Matrix<3, 3, int64_t> {{ {-69, 6, 84}, {6, -79, -47}, {84, -47, 25}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat10_3x3.symmetric(), "mat10_3x3 is not symmetric");
        diagonalize(mat10_3x3);
        assertTrue(mat10_3x3.diagonal(), "mat10_3x3 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat10_3x3), "mat10_3x3 was incorrect");
        assertFalse(positiveSemiDefinite(mat10_3x3), "mat10_3x3 positiveSemiDefinite was incorrect");

    });

    dt.addTest("4x4 matrices positive semidefinite", [] {
        Matrix<4, 4, double> mat1_4x4 = Matrix<4, 4, int64_t> {{ {91, 34, 57, -24}, {34, 78, 41, -63}, {57, 41, 62, -19}, {-24, -63, -19, 72}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat1_4x4.symmetric(), "mat1_4x4 is not symmetric");
        diagonalize(mat1_4x4);
        assertTrue(mat1_4x4.diagonal(), "mat1_4x4 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat1_4x4), "mat1_4x4 was incorrect");
        assertTrue(positiveSemiDefinite(mat1_4x4), "mat1_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat2_4x4 = Matrix<4, 4, int64_t> {{ {66, -8, -5, 38}, {-8, 72, 41, -1}, {-5, 41, 83, 6}, {38, -1, 6, 50}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat2_4x4.symmetric(), "mat2_4x4 is not symmetric");
        diagonalize(mat2_4x4);
        assertTrue(mat2_4x4.diagonal(), "mat2_4x4 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat2_4x4), "mat2_4x4 was incorrect");
        assertTrue(positiveSemiDefinite(mat2_4x4), "mat2_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat3_4x4 = Matrix<4, 4, int64_t> {{ {84, 21, -5, -29}, {21, 97, -40, -13}, {-5, -40, 54, 24}, {-29, -13, 24, 33}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat3_4x4.symmetric(), "mat3_4x4 is not symmetric");
        diagonalize(mat3_4x4);
        assertTrue(mat3_4x4.diagonal(), "mat3_4x4 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat3_4x4), "mat3_4x4 was incorrect");
        assertTrue(positiveSemiDefinite(mat3_4x4), "mat3_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat4_4x4 = Matrix<4, 4, int64_t> {{ {60, 5, -16, 47}, {5, 88, 3, -1}, {-16, 3, 81, 24}, {47, -1, 24, 83}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat4_4x4.symmetric(), "mat4_4x4 is not symmetric");
        diagonalize(mat4_4x4);
        assertTrue(mat4_4x4.diagonal(), "mat4_4x4 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat4_4x4), "mat4_4x4 was incorrect");
        assertTrue(positiveSemiDefinite(mat4_4x4), "mat4_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat5_4x4 = Matrix<4, 4, int64_t> {{ {90, 48, 2, -11}, {48, 92, -45, 36}, {2, -45, 78, -47}, {-11, 36, -47, 50}
        }}.convertTo<double>(); // positive semi-definite
        assertTrue(mat5_4x4.symmetric(), "mat5_4x4 is not symmetric");
        diagonalize(mat5_4x4);
        assertTrue(mat5_4x4.diagonal(), "mat5_4x4 is not diagonal");
        assertTrue(nonNegativeDiagonal(mat5_4x4), "mat5_4x4 was incorrect");
        assertTrue(positiveSemiDefinite(mat5_4x4), "mat5_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat6_4x4 = Matrix<4, 4, int64_t> {{ {-11, -28, -27, 64}, {-28, 10, -6, -15}, {-27, -6, -34, 11}, {64, -15, 11, -85}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat6_4x4.symmetric(), "mat6_4x4 is not symmetric");
        diagonalize(mat6_4x4);
        assertTrue(mat6_4x4.diagonal(), "mat6_4x4 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat6_4x4), "mat6_4x4 was incorrect");
        assertFalse(positiveSemiDefinite(mat6_4x4), "mat6_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat7_4x4 = Matrix<4, 4, int64_t> {{ {-57, -67, 0, -20}, {-67, 46, -31, 15}, {0, -31, -47, -63}, {-20, 15, -63, -69}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat7_4x4.symmetric(), "mat7_4x4 is not symmetric");
        diagonalize(mat7_4x4);
        assertTrue(mat7_4x4.diagonal(), "mat7_4x4 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat7_4x4), "mat7_4x4 was incorrect");
        assertFalse(positiveSemiDefinite(mat7_4x4), "mat7_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat8_4x4 = Matrix<4, 4, int64_t> {{ {-60, -30, 19, -37}, {-30, 25, -23, 27}, {19, -23, 99, -16}, {-37, 27, -16, -79}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat8_4x4.symmetric(), "mat8_4x4 is not symmetric");
        diagonalize(mat8_4x4);
        assertTrue(mat8_4x4.diagonal(), "mat8_4x4 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat8_4x4), "mat8_4x4 was incorrect");
        assertFalse(positiveSemiDefinite(mat8_4x4), "mat8_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat9_4x4 = Matrix<4, 4, int64_t> {{ {-81, -40, -11, -2}, {-40, -51, -67, -51}, {-11, -67, -13, 3}, {-2, -51, 3, -22}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat9_4x4.symmetric(), "mat9_4x4 is not symmetric");
        diagonalize(mat9_4x4);
        assertTrue(mat9_4x4.diagonal(), "mat9_4x4 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat9_4x4), "mat9_4x4 was incorrect");
        assertFalse(positiveSemiDefinite(mat9_4x4), "mat9_4x4 positiveSemiDefinite was incorrect");

        Matrix<4, 4, double> mat10_4x4 = Matrix<4, 4, int64_t> {{ {-64, -21, -29, -24}, {-21, -16, -7, 23}, {-29, -7, -14, 30}, {-24, 23, 30, -66}
        }}.convertTo<double>(); // not positive semi-definite
        assertTrue(mat10_4x4.symmetric(), "mat10_4x4 is not symmetric");
        diagonalize(mat10_4x4);
        assertTrue(mat10_4x4.diagonal(), "mat10_4x4 is not diagonal");
        assertFalse(nonNegativeDiagonal(mat10_4x4), "mat10_4x4 was incorrect");
        assertFalse(positiveSemiDefinite(mat10_4x4), "mat10_4x4 positiveSemiDefinite was incorrect");

    });

    dt.addTest("matrices with zero in the diagonal entries", [] {
        Matrix<2, 2, double> zero2x2 = Matrix<2, 2, double>::all(0);
        zero2x2[0, 1] = -1;
        zero2x2[1, 0] = -1;
        assertTrue(zero2x2.symmetric());
        diagonalize(zero2x2);
        assertTrue(zero2x2.diagonal(), "zero2x2 is not diagonal");
        assertFalse(positiveDiagonal(zero2x2), "zero2x2 is not correct");

        Matrix<3, 3, double> zero3x3 = Matrix<3, 3, double>::all(0);
        zero3x3[0, 1] = -41;
        zero3x3[1, 2] = 231;
        zero3x3[1, 0] = -41;
        zero3x3[2, 1] = 231;
        assertTrue(zero3x3.symmetric());
        diagonalize(zero3x3);
        assertTrue(zero3x3.diagonal(), "zero3x3 is not diagonal");
        assertFalse(positiveDiagonal(zero3x3), "zero3x3 is not correct");
    });

    dt.run();
    std::cout << dt;
    return getErrorCode(dt.getResults());
}