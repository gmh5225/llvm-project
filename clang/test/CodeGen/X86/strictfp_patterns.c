// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 %s -O2 -emit-llvm -o - -triple x86_64-unknown-unknown -ffreestanding -ffp-exception-behavior=maytrap -Wall -Werror | FileCheck %s

#include <immintrin.h>

// PR104848 - ensure the _mm_set_ss/d headers don't implicity promote any integer/fp values.

// CHECK-LABEL: @test_mm_set_ss(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT3_I:%.*]] = insertelement <4 x float> <float poison, float 0.000000e+00, float 0.000000e+00, float 0.000000e+00>, float [[NUM:%.*]], i64 0
// CHECK-NEXT:    ret <4 x float> [[VECINIT3_I]]
//
__m128 test_mm_set_ss(float num)
{
    return _mm_set_ss(num);
}

// CHECK-LABEL: @test_mm_set_sd(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <2 x double> <double poison, double 0.000000e+00>, double [[NUM:%.*]], i64 0
// CHECK-NEXT:    ret <2 x double> [[VECINIT1_I]]
//
__m128d test_mm_set_sd(double num)
{
    return _mm_set_sd(num);
}
