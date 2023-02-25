## Overview

Is an ARM8.2a from 2019, intended for datacenters and high-performance computing use.

These are the features shown by cpuinfo `fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm lrcpc dcpop asimddp ssbs`. So don't have SVE.

### Documents

- Arm Neoverse N1 Core: Technical Reference Manual (640 pages).
- Arm Neoverse Core N1: Performance Analysis Methodology (34 pages).
- Arm Neoverse N1: PMU Guide (84 pages).
- 


### FLOPs

The table of events doesn't show any signs of SVE. It just says ASE_SPEC (Advanced SIMD Extension, also known as NEON or ASIMD). The ASE_SPEC is specified in [Arm Architecture Reference Manual for A-profile architecture](https://developer.arm.com/documentation/ddi0487/latest) among others:

Name              | Event | Description
----------------- |-------| -----------
INST_SPEC         | r1b   | Counts instructions that are Speculatively executed (not necessarily retired or execueted).
DP_SPEC           | r73   | Counts each integer data-processing operations.
ASE_SPEC          | r74   | Counts each operation counted by INST_SPEC that is an Advanced SIMD data-processing operation. 
VFP_SPEC          | r75   | Counts operations speculatively executed, scalar floating-point. SIMD is not included.

You can't calculate anything interesting, just a hint of non-SIMD floating point operations and ARM NEON utilization.

### Other resources

- [Wikichip](https://en.wikichip.org/wiki/arm_holdings/microarchitectures/neoverse_n1)