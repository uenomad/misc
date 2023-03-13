### Bandwidth

Cache misses comparison between Skylake and Icelake.

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