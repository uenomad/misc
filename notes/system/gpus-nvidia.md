## Summary

- `dcgmi` is a remote `nvidia-smi`.
- It uses its own `libdcgm.so` which at the same time that library uses `libnvml.so`.
- nvidia-smi uses `libnvml.so`, but dynamically open.
- `libnvml.so` has metrics since CUDA 11.8.0, because nvml.h from CUDA 11.7.0 doesn't have any `nvmlGpmMetricsGet` reference. In fact we can found this information: `Last week's release of NVIDIA CUDA 11.8 already included a NVIDIA 520 (or R520) Linux driver option while NVIDIA is now in the process of releasing the v520.61.05 standalone driver.`.
- You can see through [dcgmi](./helps/dcgmi.txt) and [nvidia-smi](./helps/nvidia-smi.txt) helpers, that dmon does the same.
- Then, we assume that NVML can be used to get metrics.

## NVML (library) and NVIDIA-SMI (tool)

You can find the latest API reference [here](https://docs.nvidia.com/deploy/nvml-api/group__GPM.html#group__GPM).

## DCGM and DCGMI (tool)

The NVIDIA Data Center GPU Manager DCGMI ([website](https://docs.nvidia.com/datacenter/dcgm/latest/user-guide/getting-started.html), [Github](https://github.com/NVIDIA/DCGM)) simplifies administration of NVIDIA Datacenter (previously “Tesla”) GPUs in cluster and datacenter environments.

If we check library dependencies we find:
```
ldd dcgmi
> libdcgm.so.3 => /usr/lib64/libdcgm.so.3 (0x00001549e62d1000)

ldd libdcgm.so.3
> #Nothing interesting 

nm libdcgm.so.3
> #A lot of DCGM library symbols like dcgmProfGetSupportedMetricGroups
```

`nv-hostengine`, is the DAEMON initializer and binary around the DCGM shared library. Its main job is to instantiate the DCGM library as a persistent standalone process, including appropriate management of the monitoring and management activities. Instead running and contacting the daemon by `dcgmi` tool, you can use `libcgm.so` directly (its kwown as embedded mode).

### Installation and running

I have installed DCGM, including its tool by:
```
sudo apt-get install datacenter-gpu-manager 

# Runing the DCGM
sudo systemctl --now enable nvidia-dcgm

# More info
journalctl -u nvidia-dcgm
> oct 20 15:48:31 7420 systemd[1]: Started NVIDIA DCGM service.
> oct 20 15:48:31 7420 nv-hostengine[233256]: Error: Failed to initialize NVML
> oct 20 15:48:31 7420 nv-hostengine[233256]: Error: DCGM failed to start embedded engine
# 
```
It seems that requires NVML. In fact in the code has a NVML Wrapper and the website says `It sits on top of the NVIDIA driver, NVML, and the CUDA Toolkit`.