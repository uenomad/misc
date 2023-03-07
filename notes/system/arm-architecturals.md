- Performance Monitors: The Performance Monitors have a wide feature set, flexible selection of counted events and are read/write in
  operation.
- Activity Monitors: The Activity Monitors have a narrow feature set, limited selection of counted events, and are read-only in operation.

### MSR registers

- Old MCR and MRC don't exist in ARM AArch64. The classic<br> `asm volatile("mcr p15, 0, %0, c14, c3, 1" : : "r" (val))` have to be replaced by:<br>
`MRS <Xt>,<systemreg> #read`<br>
`MSR <systemreg>, <Xt> #Write`

### CPUID

There is no CPUID in ARM, you have to access to these registers through MRS instruction.

| Register      | Description                                                 |
|---------------|-------------------------------------------------------------|
| MIDR_EL1      | Model identification.                                       |
| PMSELR_EL0    | Performance Monitors Event Counter Selection Register.      |
| PMUSERENR_EL0 | Enables or disables EL0 access to the Performance Monitors. |
| PMCR_EL0      | Performance Monitors Control Register.                      |
| CLIDR_EL1     | Cache Level ID Register.                                    |
| CCSIDR_EL1    | Current Cache Size ID Register.                             |
| CCSIDR2_EL1   | Current Cache Size ID Register 2.                           |
| ID_DFR0_EL1   | AArch32 Debug Feature Register 0.                           |                           |
| MVFR0_EL1     | Some SIMD information.                                      |
| SMCR_EL1      | Some SVE information.                                       |

System registers exposed by the system:
- `/sys/devices/system/cpu/cpu0/regs/identification/midr_el1`
- `/sys/devices/system/cpu/cpu0/regs/identification/revidr_el1`

### Memory-mapped PMU registers

Registers that are accessible through the external debug interface (Advanced Peripheral Bus, APB).

### Resources

- [Debug register interfaces](https://developer.arm.com/documentation/ddi0500/e/debug/debug-register-interfaces).
- [Kernel.org on ARM64 CPU Feature Registers](https://www.kernel.org/doc/html/latest/arm64/cpu-feature-registers.html)