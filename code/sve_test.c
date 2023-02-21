#include <stdio.h>
#include <stdlib.h>
#include <arm_neon.h>
#ifdef __ARM_FEATURE_SVE
#include <arm_sve.h>
#endif

#define SVE64  0
#define SVE32  0
#define SVE16  0
#define NEON64 0
#define NEON32 1
#define NEON16 0
#define DOUBLE 0
#define FLOAT  0

#if SVE64
#define fl_type                   svfloat64_t
#define fl_value(vX, v)           vX = svdup_f64(v)
#define fl_operation(v3, v2, v1)  v3 = svadd_f64_x(svptrue_b64(), v2, v1)
#elif SVE32
#define fl_type                   svfloat32_t
#define fl_value(vX, v)           vX = svdup_f32(v)
#define fl_operation(v3, v2, v1)  v3 = svadd_f32_x(svptrue_b32(), v2, v1)
#elif SVE16
#define fl_type                   svfloat16_t
#define fl_value(vX, v)           vX = svdup_f16(v)
#define fl_operation(v3, v2, v1)  v3 = svadd_f16_x(svptrue_b16(), v2, v1)
#elif NEON64
#define fl_type                   float64x2_t
#define fl_value(vX, v)           vX = vdupq_n_f64(v)
#define fl_operation(v3, v2, v1)  v3 = vaddq_f64(v2, v1)
#elif NEON32
#define fl_type                   float32x4_t
#define fl_value(vX, v)           vX = vdupq_n_f32(v)
#define fl_operation(v3, v2, v1)  v3 = vaddq_f32(v2, v1)
#elif NEON16
#define fl_type                   float16x8_t
#define fl_value(vX, v)           vX = vdupq_n_f16(v)
#define fl_operation(v3, v2, v1)  v3 = vaddq_f16(v2, v1)
#elif DOUBLE
#define fl_type                   double
#define fl_value(vX, v)           vX = v
#define fl_operation(v3, v2, v1)  v3 = (v2 + v1)
#elif FLOAT
#define fl_type                   float
#define fl_value(vX, v)           vX = v
#define fl_operation(v3, v2, v1)  v3 = v2 + v1
#endif

static void test(int iters)
{
    int i;

    fl_type v1;
    fl_type v2;
    fl_type v3;

    fl_value(v1, 2.0);
    fl_value(v2, 3.0);

    for (i = 0; i < iters; ++i) {
        fl_operation(v3, v2, v1);
    }
}

int main(int argc, char *argv[])
{
    int iters = 20000;
    #if SVE64 || SVE32 || SVE16
    #ifdef __ARM_FEATURE_SVE
            int bytes = svcntb(); //Count the number of 8-bit elements in a vector
        #else
            int bytes = 0;
        #endif
        if (bytes) {
            printf("SVE is available. The length is %d bytes (%d bits)\n", bytes, bytes*8);
        } else {
            printf("SVE is unavailable.\n");
            return 0;
        }
    #endif
    if (argc > 1) {
        iters = atoi(argv[1]);
    }
    test(iters);
    return 0;
}
