## Overview



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

Comments:
- There are 16MB of L3 per CCX. There are 2 CCX per CCD (_lthree[1:0]), and up to 8 CCDs. The scope L3 is per CCX. Because one chunk of L3 per CCX (6 counters).
- If there are up to 8 CCDs, there are up to 16 CCX, which means up to 64 cores and 128 threads. Like the Zen3 EPYC 7742.

### Cache

| Event                             | Value              | PMC                      | Information                               |
|-----------------------------------|--------------------|--------------------------|-------------------------------------------|
| L2 Cache Access from DC Miss (Pf) | 0x43C860           | PMCx060 (L2RequestG1)    | Name says prefetch is included.           |
| L2 Cache Miss from DC Miss        | 0x430864           | PMCx064 (L2CacheReqStat) | DC is L1 Data Cache, confirmed by Perf.   |
| L3 Miss (includes Chg2X)          | 0xFF0F000000400104 | L3PMCx04 (L3LookupState) | This data was found in PPR for Model 31h. |

- The general purpose PMCs can be read by using Perf. But in case 'L3 Miss' we are not sure.
- These event values are 64 bits long. If break down the 'L3 Miss' event and compare with the ChL3PmcCfg, we will notice that  the 63:56 bits are used to select the threads to account, bits 7:0 for the event selection (which matches with 'L3PMCx04 All L3 Cache Requests' or 'L3LookupState'), and so on.

### Bandwidth

Strategies:
- L2 through PMCs. If using Perf the scope would be per process. If using MSR you have to take 1 PMC per thread and the scope would be per node.
- L3 through L3PMCs. If using MSR you have to take 1 L3PMC per CCX or L3 slice. If using Perf too many doubts.
- DF PMCs. If using MSR we don't have multiplexing. If using Perf too many doubts.
- HSMP. The event `GetMaxDDRBandwidthAndUtilization` it is supposed to return the bandwidth, but it has to be tested in Zen2.

On BSC AMD 7742 node, we found `perf list` returned `dram_channel_data_controller_X` events, which didn't work (<not supported>). Replacing them by the raw numbers `perf stat -e r00000000004038C7,r00000001004038C7,...` it worked, but shown too small values to calculate the `perf bench mem memcy --size 10GB` accurate bandwidth. Without perf the multiplexing is not available, so this is a problem. The same happened with `l3_misses` event, which was not supported. Translating to Perf event number `r0104` or the raw value `rFF0F000000400104` we got an extremely low value.

The direct solution through MSR seemed a better candidate for L3 and DF than Perf.

You can use the DF_PERF to count CAS per channel. The problem, you have 4 counters but 8 events (1 per channel). Maybe you can solve it by using Perf and its automatic multiplexing. But we are not sure that if the register would keep counting when there are multiple processes in a node, nor under some older Kernel versions, Perf would understand the raw values.











