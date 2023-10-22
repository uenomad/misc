## Summary

- `xpu-smi` it is like `nvidia-smi`.
- Its a binary, not a script. Is linked with `libze_loader.so`.
- It doesn't seem to offer metrics as we can see in [xpu-smi](./helps/xpu-smi.txt) helper.

## OneAPI Level Zero (library)

The OneAPI Level Zero (Level Zero) provides low-level direct-to-metal interfaces to offload accelerator devices, tailored to the devices in a oneAPI platform. Level Zero supports broader language features such as function pointers, virtual functions, unified memory, and I/O capabilities while also providing fine-grain explicit controls needed by higher-level runtime APIs including metrics reporting. While heavily influenced by other low-level APIs, such as OpenCL and Vulkan, Level Zero is designed to evolve independently.

Most applications should not require the additional control provided by the Level-Zero API. The Level-Zero API is intended for providing explicit controls needed by higher-level runtime APIs and libraries.

Its final compiled library is `libze_loader.so`.

### Installation

https://github.com/oneapi-src/level-zero

```
mkdir build
cd build
cmake .. --install-prefix=/home/user/opt/level-zero-1.11.0
cmake --build . --config Release
cmake --build . --config Release --target package
cmake --build . --config Release --target install
```

### Subsystems

- [Core](https://spec.oneapi.io/level-zero/1.0.4/core/PROG.html).
- [Sysman](https://spec.oneapi.io/level-zero/1.0.4/sysman/PROG.html) is the System Resource Management library used to monitor and control the power and performance of accelerator devices.

For each selected device handle, applications can cast it to a Sysman device handle to manage system resources of the device.
 
| API                                                               | Type                |
|-------------------------------------------------------------------|---------------------|
| [Core](https://spec.oneapi.io/level-zero/1.0.4/core/api.html)     | ze_device_handle_t  |
| [Sysman](https://spec.oneapi.io/level-zero/1.0.4/sysman/api.html) | zes_device_handle_t |


### Power control

Punit is a micro-controller on the device that controls the voltage and frequency given a power setting. When the current or temperature are too high, the Punit throttles the frequencies/voltages of the device down to their minimum values, severely impacting performance.

3 types of power control:

| Limit     | Window        | Description                                                                                                                                                                                                       |
|-----------|---------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Peak      | Instantaneous | Punit tracks the instantaneous power. When this exceeds a programmable threshold, the Punit will aggressively throttle frequencies/voltages. The threshold is referred to as PL4 - Power Limit 4 - or peak power. |
| Burst     | 2ms           | Punit tracks the 2ms moving average of power. When this exceeds a programmable threshold, the Punit starts throttling frequencies/voltages. The threshold is referred to as PL2 - Power Limit 2 - or burst power. |
| Sustained | 28sec         | Punit tracks the 28sec moving average of power. When this exceeds a programmable threshold, the Punit throttles frequencies/voltages. The threshold is referred to as PL1 - Power Limit 1 - or sustained power.   |

https://spec.oneapi.io/level-zero/

## XPU Manager

[XPU Manager](https://github.com/intel/xpumanager) it is like `nvidia-smi`.