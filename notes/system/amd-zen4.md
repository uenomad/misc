### Links

- [ChipsAndCheese Zen4 Memory Subsystem](https://chipsandcheese.com/2022/11/08/amds-zen-4-part-2-memory-subsystem-and-conclusion/)

### HSMP

PCIe interface needs to be enabled in the BIOS. On the reference BIOS, the CBS option may be found in the following path:

Advanced > AMD CBS > NBIO Common Options > SMU Common Options > HSMP Support

If the option is disabled, the related E-SMI APIs will return -ETIMEDOUT.

The AMD HSMP driver is now part of the Linux kernel upstream starting in v5.18-rc1. Review kernel.org for updated versions of this driver.

The e_smi_tool interacts with /dev/hsmp and /sys/class/hwmon/* to read and write things. `amd_hsmp` and `amd_energy` drivers are required. To install, `asm/amd_hsmp.h` is required. The driver will set the `/dev/hsmp` file.

```
lsmod | grep amd_
amd_hsmp               16384  0
amd_energy             16384  0
```

#### Kernel files

/drivers/platform/x86/amd/hsmp.c
/arch/x86/include/asm/amd_hsmp.c

#### Links

https://github.com/AMDESE/libhsmp (library)
https://github.com/amd/amd_hsmp (old AMD driver)
https://www.kernel.org/doc/html/next/x86/amd_hsmp.html (new AMD driver)
https://github.com/amd/esmi_ib_library (sysman library and tool)
https://github.com/amd/esmi_ib_library/blob/master/ESMI_Manual.pdf (sysman manual)
https://developer.amd.com/e-sms/ (E-SMS project) 

Linux tcn1214.local.snellius.surf.nl 5.14.0-284.25.1.el9_2.x86_64 #1 SMP PREEMPT_DYNAMIC Thu Jul 20 09:11:28 EDT 2023 x86_64 x86_64 x86_64 GNU/Linux
Linux tcn888.local.snellius.surf.nl 4.18.0-372.57.1.el8_6.x86_64 #1 SMP Thu May 11 07:38:47 EDT 2023 x86_64 x86_64 x86_64 GNU/Linux
