### Prefetch

Disadvantages:
- Accesses often follow simple patterns.
- If the pattern can be identified, lines can be fetched before they are actually needed, avoiding misses.
- Danger of fetching too soon -- may be evicted.
- Can evict useful data and force additional misses.
- Can generate excessive memory traffic.

### Victim cache

A victim cache is a cache that holds evicted data from a lower level cache, but not reads data from DRAM. That lower level cache would retrieve the data directly from DRAM in case the victim cache doesn't hold the requested data.