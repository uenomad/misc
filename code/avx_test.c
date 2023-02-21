#include <time.h>
#include <stdio.h>
#include <emmintrin.h>
#include <immintrin.h>

// AMD      RYZEN       16 [15-00]
// INTEL    SKYLAKE     32 [31-00]
#if RYZEN
#define XMM_REGS 15
    #define YMM_REGS 15
    #define ZMM_REGS 0
#elif SKYLAKE
#define XMM_REGS 31
    #define YMM_REGS 31
    #define ZMM_REGS 31
#endif

#ifdef DISPERSION
#define ADD128(R1,R2,R3) "vaddpd %xmm" #R1 ",%xmm" #R2 ",%xmm" #R3 "\n\t"
#define MUL128(R1,R2,R3) "vmulpd %xmm" #R1 ",%xmm" #R2 ",%xmm" #R3 "\n\t"
#define FMA128(R1,R2,R3) "vfmadd213pd %xmm" #R1 ",%xmm" #R2 ",%xmm" #R3 "\n\t"
#define ADD512(R1,R2,R3) "vaddpd %zmm" #R1 ",%zmm" #R2 ",%zmm" #R3 "\n\t"
#define MUL512(R1,R2,R3) "vmulpd %zmm" #R1 ",%zmm" #R2 ",%zmm" #R3 "\n\t"
#define FMA512(R1,R2,R3) "vfmadd213pd %zmm" #R1 ",%zmm" #R2 ",%zmm" #R3 "\n\t"
#else
#define ADD128(N) "vaddpd %xmm1,%xmm0,%xmm" #N "\n\t"
#define MUL128(N) "vmulpd %xmm1,%xmm0,%xmm" #N "\n\t"
#define FMA128(N) "vfmadd213pd %xmm1,%xmm0,%xmm" #N "\n\t"
#define ADD256(N) "vaddpd %ymm1,%ymm0,%ymm" #N "\n\t"
#define MUL256(N) "vmulpd %ymm1,%ymm0,%ymm" #N "\n\t"
#define FMA256(N) "vfmadd213pd %ymm1,%ymm0,%ymm" #N "\n\t"
#define ADD512(N) "vaddpd %zmm1,%zmm0,%zmm" #N "\n\t"
#define MUL512(N) "vmulpd %zmm1,%zmm0,%zmm" #N "\n\t"
#define FMA512(N) "vfmadd213pd %zmm1,%zmm0,%zmm" #N "\n\t"
#endif

#define ALIGN() __asm__(".align 64\n\t");
#define KMOVB() __asm__( \
    "movl    $1, %eax\n\t" \
    "kmovb   %eax, %k3\n\t" \
    ); \

#ifdef DISPERSION
#define M_REPEAT_0(X)  "nop\n\t"
#define M_REPEAT_3(X)  X(3,2,1)
#define M_REPEAT_6(X)  X(6,5,4) M_REPEAT_3(X)
#define M_REPEAT_9(X)  X(9,8,7) M_REPEAT_6(X)
#define M_REPEAT_12(X) X(12,11,10) M_REPEAT_9(X)
#define M_REPEAT_15(X) X(15,14,13) M_REPEAT_12(X)
#define M_REPEAT_19(X) X(19,18,17) M_REPEAT_15(X)
#define M_REPEAT_22(X) X(22,21,20) M_REPEAT_19(X)
#define M_REPEAT_25(X) X(25,24,23) M_REPEAT_22(X)
#define M_REPEAT_28(X) X(28,27,26) M_REPEAT_25(X)
#define M_REPEAT_31(X) X(31,30,29) M_REPEAT_28(X)
#else
#define M_REPEAT_0(X)  "nop\n\t"
#define M_REPEAT_2(X)  X(2)
#define M_REPEAT_3(X)  X(3) M_REPEAT_2(X)
#define M_REPEAT_4(X)  X(4) M_REPEAT_3(X)
#define M_REPEAT_5(X)  X(5) M_REPEAT_4(X)
#define M_REPEAT_6(X)  X(6) M_REPEAT_5(X)
#define M_REPEAT_7(X)  X(7) M_REPEAT_6(X)
#define M_REPEAT_8(X)  X(8) M_REPEAT_7(X)
#define M_REPEAT_9(X)  X(9) M_REPEAT_8(X)
#define M_REPEAT_10(X) X(10) M_REPEAT_9(X)
#define M_REPEAT_11(X) X(11) M_REPEAT_10(X)
#define M_REPEAT_12(X) X(12) M_REPEAT_11(X)
#define M_REPEAT_13(X) X(13) M_REPEAT_12(X)
#define M_REPEAT_14(X) X(14) M_REPEAT_13(X)
#define M_REPEAT_15(X) X(15) M_REPEAT_14(X)
#define M_REPEAT_16(X) X(16) M_REPEAT_15(X)
#define M_REPEAT_17(X) X(17) M_REPEAT_16(X)
#define M_REPEAT_18(X) X(18) M_REPEAT_17(X)
#define M_REPEAT_19(X) X(19) M_REPEAT_18(X)
#define M_REPEAT_20(X) X(20) M_REPEAT_19(X)
#define M_REPEAT_21(X) X(21) M_REPEAT_20(X)
#define M_REPEAT_22(X) X(22) M_REPEAT_21(X)
#define M_REPEAT_23(X) X(23) M_REPEAT_22(X)
#define M_REPEAT_24(X) X(24) M_REPEAT_23(X)
#define M_REPEAT_25(X) X(25) M_REPEAT_24(X)
#define M_REPEAT_26(X) X(26) M_REPEAT_25(X)
#define M_REPEAT_27(X) X(27) M_REPEAT_26(X)
#define M_REPEAT_28(X) X(28) M_REPEAT_27(X)
#define M_REPEAT_29(X) X(29) M_REPEAT_28(X)
#define M_REPEAT_30(X) X(30) M_REPEAT_29(X)
#define M_REPEAT_31(X) X(31) M_REPEAT_30(X)
#endif

#define M_EXPAND(...) __VA_ARGS__
#define M_REPEAT(N, X) M_EXPAND(M_REPEAT_ ## N)(X)

#ifdef DISPERSION
#define MASM(N, X) \
    __asm__( \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
    );
#else
#define MASM(N, X) \
    __asm__( \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
        M_REPEAT(N, X) \
    );
#endif

#define F_AVX(name, macro) \
    void name (uint n_iterations) \
    { \
        ulong i; \
        ALIGN(); \
        for (i = 0; i < n_iterations; i++) { \
            macro \
        } \
    }

F_AVX(add128dp, MASM(XMM_REGS, ADD128));
F_AVX(mul128dp, MASM(XMM_REGS, MUL128));
F_AVX(fma128dp, MASM(XMM_REGS, FMA128));
F_AVX(add256dp, MASM(YMM_REGS, ADD256));
F_AVX(mul256dp, MASM(YMM_REGS, MUL256));
F_AVX(fma256dp, MASM(YMM_REGS, FMA256));
F_AVX(add512dp, MASM(ZMM_REGS, ADD512));
F_AVX(mul512dp, MASM(ZMM_REGS, MUL512));
F_AVX(fma512dp, MASM(ZMM_REGS, FMA512));

int main(int argc, char *argv[])
{
    int n = 100000000;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    #ifdef AVX128
    add128dp(n);
    mul128dp(n);
    fma128dp(n);
    #endif
    #ifdef AVX256
    add256dp(n);
    mul256dp(n);
    fma256dp(n);
    #endif
    #ifdef AVX512
    add512dp(n);
    mul512dp(n);
    fma512dp(n);
    #endif

    return 0;
}