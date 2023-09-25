### Strace

Is used to monitor and tamper with interactions between processes and the Linux kernel, which include system calls, signal deliveries, and changes of process state.

#### Examples

```
strace -c -e trace=read,write perf bench...
```