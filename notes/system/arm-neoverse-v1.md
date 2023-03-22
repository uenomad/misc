## Overview

Neoverse V1 (ARM8.2a), next generation of Neoverse N1, is the first Arm-designed core to support key performance features including Scalable Vector Extensions<sup>1</sup>, bFloat16 and Int8MatMul. Combined with platform capabilities such as DDR5 memory and PCIe Gen5 I/O. 

V1 is a super pipelined super-scalar processor which has an in-order frontend and out-of-order backend. Also has a dedicated L1/L2 cache per core, where the L2 cache is shared between the L1 data cache and the L1 instruction cache. The system could have an optional shared system level cache (SLC) in the interconnect (L3?). It is recommended to check with the platform providers for cache configurations.

This is an expansion of [ARM Neoverse N1](./arm-neoverse-n1.md). Read first that document.

### Documents

- Arm Neoverse V1 Core Performance Analysis Methodology: Paper introducing performance analysis, including PMU events and metrics (93 pages). It is like a summary, and its appendixes are very useful.
- Arm Neoverse V1 Core Technical Reference Manual: Technical details including PMU events (545 pages).
- Neoverse V1 PMU Guide: PMU details (78 pages).
- Arm Neoverse V1 Software Optimization Manual: list of instructions and their latency.

### PMUs

The Neoverse V1 CPU implements the PMU extensions of the Arm v8.4 with support for 100+ hardware events. The Neoverse V1 PMU has six configurable counter registers (PMC0 to PMC5) and one dedicated function counter to count CPU cycles.

### Instructions and cycles

4.3.4 AMU events

### FLOPs

| Name              | Event | Description                                                                                    |
|-------------------|-------|------------------------------------------------------------------------------------------------|
| INST_SPEC         | r1b   | Counts instructions that are Speculatively executed (not necessarily retired or execueted).    |
| DP_SPEC           | r73   | Counts each integer data-processing operations.                                                |
| ASE_SPEC          | r74   | Counts each operation counted by INST_SPEC that is an Advanced SIMD data-processing operation. |
| VFP_SPEC          | r75   | Counts operations speculatively executed, scalar floating-point. SIMD is not included.         |
| ASE_INST_SPEC     | r8005 | Counts NEON instructions (spec).                                                               |
| SVE_INST_SPEC     | r8006 | Counts SVE instructions (spec).                                                                |
| FP_SCALE_OPS_SPEC | r80c0 | Counts SVE floating-point element ALU operations.                                              |
| FP_FIXED_OPS_SPEC | r80c1 | Counts non-SVE floating-point element ALU operations.                                          |

Using FP_FIXED_OPS_SPEC and FP_FIXED_OPS_SPEC we can not break down the OPS per float type, but we can compute the total FLOPs.

### Cache

Take a look to [Neoverse N1 Cache section](./arm-neoverse-n1.md).

### Bandwidth

Take a look to [Neoverse N1 Bandwidth section](./arm-neoverse-n1.md).

More about BUS_ACCESS. The current version of the Arm® Architecture Reference Manual implements additional fields in the Performance Monitors Machine Identification Register, PMMIR_EL1, that were not defined when the Neoverse V1 was developed. Those fields could be useful for understanding memory system related events, so they are defined here:
- PMMIR_EL1.BUS_SLOTS: 2
- PMMIR_EL1.BUS_WIDTH: 256

### Power Control

### Other resources

- [Arm Neoverse N1 Core Technical Reference Manual](https://developer.arm.com/documentation/100616/0400/)
- [PMU events in github](https://github.com/ARM-software/data/tree/master/pmu)
- [Likwid Groups](https://github.com/RRZE-HPC/likwid/tree/master/groups/)










