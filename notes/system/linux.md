### Building kernel modules

### sysconf

Get kernel configuration constants.

| Name                       | Description                                                                          |
|----------------------------|--------------------------------------------------------------------------------------|
| _SC_LEVEL*_DCACHE_ASSOC    | Get LEVEL X of cache associativity.                                                  |
| _SC_LEVEL*_DCACHE_SIZE     | Get LEVEL X of cache size.                                                           |
| _SC_LEVEL*_DCACHE_LINESIZE | Get LEVEL X of cache line size (in bytes).                                           |
| _SC_NPROCESSORS_CONF       | The number of processors configured.  See also get_nprocs_conf(3).                   |
| _SC_NPROCESSORS_ONLN       | The number of processors currently online (available).  See also get_nprocs_conf(3). |

### sysinfo

Returns certain system statistics.

```
struct sysinfo {
   long uptime;             /* Seconds since boot */
   unsigned long loads[3];  /* 1, 5, and 15 minute load averages */
   unsigned long totalram;  /* Total usable main memory size */
   unsigned long freeram;   /* Available memory size */
   unsigned long sharedram; /* Amount of shared memory */
   unsigned short procs;    /* Number of current processes */
   ...
};
```
           
### /proc 

- /proc/meminfo
- /proc/cpuinfo

### Resources

- Power and Performance Software Analysis and Optimization
  (Jim Kukunas).
- [Google Benchmark](https://github.com/google/benchmark/tree/v1.1.0/src).