## Perf

Perf is a profiler tool for Linux 2.6+ based systems that abstracts away CPU hardware differences in Linux performance measurements and presents a simple commandline interface. Perf is based on the perf_events interface exported by recent versions of the Linux kernel.

### System call

An event group is only scheduled to be collected when all members are available to be measured. Thus, all events that will be calculated or compared together should be members of the same group, ensuring that each event metric is computed based on similar code execution.

The way perf_events emulates 64-bit counter is limited to expressing sampling periods using the number of bits in the actual hardware counters. If this is smaller than 64, the kernel silently truncates the period in this case. Therefore, it is best if the period is always smaller than 2^31 if running on 32-bit systems.

### Scope and context switch

The perf tool can be used to count events on a per-thread, per-process, per-cpu or system-wide basis. In per-thread mode, the counter only monitors the execution of a designated thread. When the thread is scheduled out, monitoring stops. When a thread migrated from one processor to another, counters are saved on the current processor and are restored on the new one.

The per-process mode is a variant of per-thread where all threads of the process are monitored. Counts and samples are aggregated at the process level. The perf_events interface allows for automatic inheritance on fork() and pthread_create(). By default, the perf tool activates inheritance.

In per-cpu mode, all threads running on the designated processors are monitored. Counts and samples are thus aggregated per CPU. An event is only monitoring one CPU at a time. To monitor across multiple processors, it is necessary to create multiple events. The perf tool can aggregate counts and samples across multiple processors. It can also monitor only a subset of the processors.

In per-cpu mode mode, samples are collected for all threads executing on the monitored CPU.

### Multiplexing

If there are more events than counters, the kernel uses time multiplexing (switch frequency = HZ, generally 100 or 1000) to give each event a chance to access the monitoring hardware. Multiplexing only applies to PMU events. With multiplexing, an event is not measured all the time. At the end of the run, the tool scales the count based on total time enabled vs time running.

Events are currently managed in round-robin fashion. Therefore each event will eventually get a chance to run. If there are N counters, then up to the first N events on the round-robin list are programmed into the PMU. In certain situations it may be less than that because some events may not be measured together or they compete for the same counter. Furthermore, the perf_events interface allows multiple tools to measure the same thread or CPU at the same time. Each event is added to the same round-robin list. There is no guarantee that all events of a tool are stored sequentially in the list.

To avoid scaling (in the presence of only one active perf_event user), one can try and reduce the number of events.

### Requirements

Requires that the kernel’s NMI watchdog and kernel pointer hiding functionality are disabled. The NMI, nonmaskable interrupt, watchdog timer programs a reoccurring APIC timer in order to detect if the kernel has become unresponsive. From the generation of the interrupt, the kernel has a certain time threshold to handle the interrupt. If this threshold is exceeded, the kernel is considered to be deadlocked, and the system is rebooted. Since the NMI watchdog uses the PMU to measure this threshold it conflicts with any application that uses the PMU. This feature can be disabled either by adding nmi_watchdog=0 to the kernel boot command-line, by writing a zero character to the file /proc/sys/kernel/nmi_watchdog, or by setting the kernel.nmi_watchdog sysctl property to zero.

The kernel pointer hiding functionality controls how the kernel prints addresses, both in logs and system files. With this feature enabled, unless the user has the necessary privileges, all kernel pointer addresses are printed as NULL. This is designed to improve security by hiding the exact location of some of the kernel’s data structures. At the same time, this makes it difficult to correlate the collected instruction pointers to kernel functions. This feature can be disabled either by setting the  kernel.kptr_restrict sysctl property to zero, or by writing a zero character to the file /proc/sys/kernel/kptr_restrict.

Additionally, the visibility of the data collection can be controlled with the  /proc/sys/kernel/perf_event_paranoid file. If this file does not exist, either the kernel was compiled without support for performance events or procfs isn’t mounted. If the file does exist, it contains a string of an integer. This integer specifies the access  restrictions enforced by the kernel for measurements. 

### Tool

You can see the events by typing `perf list` and more detailed list by `perf list --details`.

### Resources

- https://perf.wiki.kernel.org/index.php/Tutorial
- Power and Performance Software Analysis and Optimization (Jim Kukunas).