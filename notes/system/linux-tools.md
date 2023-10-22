### Valgrind

To find memory leaks.

```
valgrind ./test
```

### Strace

Is used to monitor and tamper with interactions between processes and the Linux kernel, which include system calls, signal deliveries, and changes of process state.

#### Examples

```
strace -c -e trace=read,write perf bench...
```

### Cron and Crontab

Cron is the daemon. Crontab is the tool that reads a crontab file format.


``` 
*/1 * * * * echo "hello" >> /home/name/hello.txt #writting hello every minute

```

$ ls -l /var/spool/cron/crontabs
