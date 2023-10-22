### Features

- Golden Cove cores.
- AVX512-FP16.
- Advanced Matrix Extensions (AMX).
- DDR5 memory support up to DDR5-4800.
- On-package HBM2e Memory as L4 cache on some models.

### Uncore

- A Global Control unit over a set of PMON units (UBOX, IMC, CHA...).
- Each PMON contains a set of counters, and its unit control/status registers.
- Is a per-socket resource.
- Several unit counter control registers are still 32b, some 64b. All are addressable as 64b registers.

```
U_MSR_PMON_GLOBAL_CTL (0x2FF0)
    bits 63:01: reserved
    bits 00:00: freeze all
```

### Reading IMC frequency

- UCLK is Unified Memory Controller Clock. Is MSR. Is variable.
- DCLK is DRAM Clock or Data Clock. Is PCI. Is constant.
- The UBox is the only PMON block without a separate Unit Control register.
- The only way to freeze the UBox counters is to use the global freeze `U_MSR_PMON_GLOBAL_CTL`.

```
U_MSR_PMON_FIXED_CTL (0x2FDE)
    bits 31:23: reserved
    bits 22:22: freeze all
    bits 21:21: reserved
    bits 20:20: ov_en
    bits 19:00: reserved
```

### Reading bandwidth

- There are 4 IMCs per socket. Two channels per IMC.
- MMIO, device 0x3251. In Ice Lake was 0x3451.
- The BAR address "MMIO_ADDR1" is at offset 0xD0 in the PCICFG space.
- The BAR address "MMIO_ADDR2" is at offset 0xD8+(0x04*imc_id) in the PCICFG space.
- Add both addresses and the register offset 0x2290. Use that address in mmap() in "/dev/mem" file.
- Read both 0x00 (RD DDR) and 0x08 (WR DDR) offsets.
- We are reading a Free Running Counter, there is no need to access to every channel space.

- WPQ: Write Pending Queue

### Reading cache

Inherited from Skylake. But it does [not include L2_TRANS.L2_WB to count data that leaves the L2 level](https://github.com/RRZE-HPC/likwid/wiki/L2-L3-MEM-traffic-on-Intel-Skylake-SP-CascadeLake-SP). This concrete event has to be replaced by the sum of:

| Event                   | Ev,Umask | Description                                                                                                                                                                         |
|-------------------------|----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| L2_LINES_OUT.NON_SILENT | 26,01    | Count lines evicted from L2 due cache fills. Evicted lines are delivered to the L3, which may or may not cache them, according to system load and priorities.                       |
| L2_LINES_OUT.SILENT     | 26,02    | Counts the number of lines that are silently dropped by L2 cache when triggered by an L2 cache fill. These lines are typically in Shared or Exclusive state. A non-threaded event.  |

* [Intel Perfmon Events](https://perfmon-events.intel.com/spxeon.html).