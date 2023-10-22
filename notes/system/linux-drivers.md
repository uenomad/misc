## Sysfs

- Virtual system files with information about devices and their drivers.
- Mounted in /sys.
- Supported buses are: ACPI, PCI, USB...
- Folders:
  - /sys/class: each of the device classes that have been registered on the system. You can find symbolic links to actual devices.
  - /sys/devices: each chip has its own directory.
  - /sys/devices/hwmon: all the sensors. [More about HWMON](https://docs.kernel.org/hwmon/sysfs-interface.html).
  - /sys/devices/virtual: not real devices.
- You can use libsensors.so to avoid Sysfs.

## power_meter

- Optional power capping mechanism.
- ACPI 4.0 spec.
- Sysfs interface.

[Kernel.org](https://www.kernel.org/doc/Documentation/hwmon/acpi_power_meter)

## rapl

- Power capping framework: exposed by Sysfs at /sys/devices/virtual/powercap/intel-rapl.

[Kernerl.org](https://www.kernel.org/doc/html/next/power/powercap/powercap.html)

## Sysfs