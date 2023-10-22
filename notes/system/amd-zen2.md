## Overview

- 64 bytes of cache line size.
- There are 4 cores/8 threads per CCX.
- There are 16MB of L3 per CCX. There are 2 CCX per CCD (_lthree[1:0]), and up to 8 CCDs. The scope L3 is per CCX. Because one chunk of L3 per CCX (6 L3PMC counters).
- If there are up to 8 CCDs, there are up to 16 CCX, which means up to 64 cores and 128 threads. Like the Zen2 EPYC 7742 or Zen3 EPYC 7773X.
- The L3 is a victim cache (confirmed by [Wikichip](https://en.wikichip.org/wiki/amd/microarchitectures/zen_2)).

### PMUs

There are 6 core performance events counters per thread, 6 performance events counters per L3 complex and 4 Data Fabric performance events counters mapped to the RDPMC instruction.

- The RDPMC[5:0] instruction accesses core events.
- The RDPMC[9:6] instruction accesses data fabric events.
- The RDPMC[F:A] instruction accesses L3 cache events.
- The RDMSR uses the full MSRXXXX_XXXX address.

Section 'Performance Monitor Counters' of 'PPR for Family 17h'. Also see `smp_call_function_single` function.

| Name        | Address      | X           | Scope  | Description                  |
|-------------|--------------|-------------|--------|------------------------------|
| PERF_CTL    | MSRC001_020X | 0,2,4,6,8,A | Thread | 6 performance event selects  |
| PERF_CTR    | MSRC001_020X | 1,3,5,7,9,B | Thread | 6 performance event counters |
| ChL3PmcCfg  | MSRC001_023X | 0,2,4,6,8,A | L3     | 6 performance event selects  |
| ChL3Pmc     | MSRC001_023X | 1,3,5,7,9,B | L3     | 6 performance event counters |
| DF_PERF_CTL | MSRC001_024X | 0,2,4,6     | Socket | 4 performance event selects  |
| DF_PERF_CTR | MSRC001_024X | 1,3,5,7     | Socket | 4 performance event selects  |

### Cache

| Event                             | Value              | PMC                       | Information                               |
|-----------------------------------|--------------------|---------------------------|-------------------------------------------|
| L2 Cache Access from DC Miss (Pf) | 0x43C860           | PMCx060 (L2RequestG1)     | Name says prefetch is included.           |
| L2 Cache Miss from DC Miss        | 0x430864           | PMCx064 (L2CacheReqStat)  | DC is L1 Data Cache, confirmed by Perf.   |
| L2 Cache Miss from L2 HWPF (1)    | 0x431F71           | PMCx071 (L2PfMissL2HitL2) | Prefetches of L2 that hits L3.            |
| L2 Cache Miss from L2 HWPF (2)    | 0x431F72           | PMCx072 (L2PfMissL2L3)    | Prefetches of L2 that misses L3.          |
| L3 Miss (includes Chg2X)          | 0xFF0F000000400104 | L3PMCx04 (L3LookupState)  | This data was found in PPR for Model 31h. |

- The general purpose PMCs can be read by using Perf. But in case 'L3 Miss' we are not sure.
- These event values are 64 bits long. If break down the 'L3 Miss' event and compare with the ChL3PmcCfg, we will notice that  the 63:56 bits are used to select the threads to account, bits 7:0 for the event selection (which matches with 'L3PMCx04 All L3 Cache Requests' or 'L3LookupState'), and so on.

### Bandwidth

Strategies:
- L2 misses by PMCs. If using Perf the scope would be per process. If using MSR you have to take 1 PMC per thread and the scope would be per node.
- L3 misses by L3PMCs. If using MSR you have to take 1 L3PMC per CCX or L3 slice. If using Perf too many doubts (¿It will work? ¿What happens when multiple process are using L3PMCs?).
- CAS count by DF PMCs. If using MSR we don't have multiplexing (8 events/4 counters). If using Perf too many doubts.
- Bandwidth by HSMP. The event `GetMaxDDRBandwidthAndUtilization` it is supposed to return the bandwidth, but it has to be tested in Zen2.

Perf test commands:
```
Command #1:
perf stat -e r0000000000403807,r0000000000403847,r0000000000403887,r00000000004038C7 taskset -c 0 perf bench mem memcpy --size 10GB
perf stat -e r0000000100403807,r0000000100403847,r0000000100403887,r00000001004038C7 taskset -c 0 perf bench mem memcpy --size 10GB
Command #2:
perf stat -e r3807,r3847,r3887,r38c7 taskset -c 0 perf bench mem memcpy --size 10GB
perf stat -e r38107,r38147,r38187,r381c7 taskset -c 0 perf bench mem memcpy --size 10GB
Command #3:
perf stat -e dram_channel_data_controller_0,dram_channel_data_controller_1,dram_channel_data_controller_2,dram_channel_data_controller_3 taskset -c 0 perf bench mem memcpy --size 10GB
perf stat -e dram_channel_data_controller_4,dram_channel_data_controller_5,dram_channel_data_controller_6,dram_channel_data_controller_7 taskset -c 0 perf bench mem memcpy --size 10GB
Command #4:
perf stat --metric-no-group -M nps1_die_to_dram taskset -c 0 perf bench mem memcpy --size 10GB
Command #5:
perf stat -e l3_misses taskset -c 0 perf bench mem memcpy --size 10GB
Command #6 (L2 misses including prefetch):
perf stat -M all_l2_cache_misses taskset -c 0 perf bench mem memcpy --size 10GB
```

In order to avoid multiplexing, we are going to split the events by half and set the bench program to a specific CPU through taskset. Also we are going to perform 2 tests per command to compare their output. Morever we are adding an L2 test to compare. Results:

| Command | Node              |   Sum of values | Bytes transferred |  GB |  GB/s |
|---------|-------------------|----------------:|------------------:|----:|------:|
| #1 (DF) | 7773X kernel 4.18 |         699.232 |        44.750.848 |   0 |     0 |
| #1 (DF) | 7742_ kernel 4.18 |         112.599 |         7.206.336 |   0 |     0 |
| #2      | 7773X kernel 4.18 |   4.590.684.470 |   293.803.806.080 | 293 |    26 |
| #2      | 7742_ kernel 4.18 |  16.232.284.663 | 1.051.308.295.552 | 1TB |    74 |
| #3      | 7773X kernel 4.18 |   5.119.642.890 |   327.657.144.960 | 327 |    29 |
| #3      | 7742_ kernel 4.18 | <not supported> |                 - |   - |     - |
| #4      | 7773X kernel 4.18 |   5.116.843.009 |   327.477.952.576 | 327 |    29 |
| #4      | 7742_ kernel 4.18 | <not supported> |                 - |   - |     - |
| #5 (L3) | 7773X kernel 4.18 |   2.908.836.466 |   186.165.533.824 | 186 |    16 |
| #5 (L3) | 7742_ kernel 4.18 | <not supported> |                 - |   - |     - |
| #6 (L2) | 7773X kernel 4.18 |   3.066.661.424 |   196.266.331.136 | 196 |    17 |
| #6 (L2) | 7773X kernel 4.18 |   2.288.483.966 |   146.462.973.824 | 146 |    10 |

It makes sense that the L2 Misses counters are below the CAS count from the channels for test #2, #3 and #4? Just if we consider that other processes are intensely accessing to DRAM or hardware prefetchers are avoiding the L2.