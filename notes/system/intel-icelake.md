### Read bandwidth

How to:
- There are 4 IMCs per socket. Two channels per IMC.
- MMIO, device 0x3451.
- The BAR address "MMIO_ADDR1" is at offset 0xD0 in the PCICFG space.
- The BAR address "MMIO_ADDR2" is at offset 0xD8+(0x04*imc_id) in the PCICFG space.
- Add both addresses and the register offset 0x2290. Use that address in mmap() in "/dev/mem" file.
- Read both 0x00 (RD DDR) and 0x08 (WR DDR) offsets.

|                                    | Address  | Comments                                                                          | 
|------------------------------------|----------|-----------------------------------------------------------------------------------|
| PCI dev. vendor id                 | 0x8086   |                                                                                   |
| PCI dev. id                        | 0x3451   |                                                                                   |
| IMC Free Running Counters (RD DDR) | 0x2290   | Is global, not per channel. Also known as MC_MMIO_PMON_FRCTR_RD_BW. 48 bits wide. |
| IMC Free Running Counters (WR DDR) | 0x2298   | Is global, not per channel. Also known as MC_MMIO_PMON_FRCTR_WR_BW. 48 bits wide. |
| IMC Free Running Counters (DCLK)   | 0x22B0   | Same. Known as MC_MMIO_PMON_FRCTR_DCLK. Count DDR clocks captured in MC.          |
|                                    | 0x030000 | Command to enable something.                                                      |
| UNC_M_CAS_COUNT.ALL                | 0x423F04 | In case you want to use MC_CHy_PCI_PMON_CTR instead free running ones.            |

Docs:
- 3rd gen Xeon Uncore Performance Monitoring.
  - 1.8.2 Uncore Performance Monitoring State in PCICFG space.
  - 1.9 Some Guidance for SW.
  - 2.4 Memory Controller (IMC) Performance Monitoring.
- [Perfmon Events](https://perfmon-events.intel.com/) > Ice Lake Server Events > Uncore.


### Read bandwidth through cache

Cache misses comparison between Skylake (6126) and Icelake (8352Y).

| Node  | Name            | Event  | Counter       | GB  | GB/s |
|-------|-----------------|--------|---------------|-----|-----:|
| 6126  | L2_RQSTS.MISS   | 0x3f24 | 2.355.682.352 | 150 |    8 |
| 6126  | L2_TRANS.L2_WB  | 0x40f0 | 1.776.690.174 | 113 |    6 |
| 6126  | L2_LINES_IN.ALL | 0x1ff1 | 2.355.722.583 | 150 |    8 |
| 8352Y | L2_RQSTS.MISS   | 0x3f24 | 3.607.578.952 | 230 |    9 |
| 8352Y | L2_TRANS.L2_WB  | 0x40f0 | 3.851.183.299 | 246 |   10 |
| 8352Y | L2_LINES_IN.ALL | 0x1ff1 | 3.940.322.599 | 252 |   10 |

```
perf stat -e r3f24,r40f0,r1ff1 taskset -c 0 perf bench mem memcpy --size 10GB
```

### Uncore

```
U_MSR_PMON_GLOBAL_CTL (0x0700)
    bits 63:63: freeze all
    bits 62:62: wk_on_pmi
    bits 61:61: unfreeze all
    bits 60:00: pmi_core_sel
```

### IMC frequency

```
U_MSR_PMON_FIXED_CTL (0x0703)
    bits 31:23: reserved
    bits 22:22: freeze all
    bits 21:21: reserved
    bits 20:20: ov_en
    bits 19:00: reserved
```

### Bandwdith

2.17.8 MSRs Specific to the 4th Generation Intel® Xeon® Scalable Processor Family Based on Sapphire Rapids Microarchitecture
20.3.6.6 Uncore Performance Monitoring Facilities in the 4th Generation Intel® Core™ Processors