### Prefetch

Disadvantages:
- Accesses often follow simple patterns.
- If the pattern can be identified, lines can be fetched before they are actually needed, avoiding misses.
- Danger of fetching too soon -- may be evicted.
- Can evict useful data and force additional misses.
- Can generate excessive memory traffic.

### Numa node

Non-uniform memory access (NUMA) is a computer memory design used in multi-socket systems, where the memory access time depends on the memory location relative to the processor. Under NUMA, a processor can access its own local memory faster than non-local memory (memory local to another processor or memory shared between processors). The benefits of NUMA are limited to particular workloads, notably on servers where the data is often associated strongly with certain tasks or users.

NUMA attempts to address the bandwidth starving by providing separate memory for each processor, avoiding the performance hit when several processors attempt to address the same memory.

Remote memory access has additional latency overhead to local memory access, as it has to traverse the interconnect and connect to the remote memory controller. As a result of the different locations memory can exist, this system experiences “non-uniform” memory access time.

Nodes Per Socket (NPS). NPS4 means four NUMA nodes per socket.

In case of AMD, XGMI is the bus that interconnects each socket.

### Memory interleaving

- Memory channel interleaving happens when populating DIMM's across different channels. The contiguous memory addresses are distributed between DIMM's space equally, taking advantage of all channels of the system therefore increasing bandwidth. 
- A rank is a memory bank but beloning to different physical chip. Rank interleaving happens when there are dual-ranked DIMMs (or doble sided). It improves the memory latency.
- When increasing the number of DIMM's per channel, the throughput may decrease because the memory controllers have to increase the control commands. Basically you are increasing management overhead.

Visit [Frank Denneman blog](https://frankdenneman.nl/2015/02/20/memory-deep-dive/) for more information.

6-way interleave
bank interleave