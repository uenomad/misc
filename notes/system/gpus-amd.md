## Summary

- `rocm-smi` is like `nivida-smi` and `xpu-smi`.
- `rocm-smi` is a Python script, and it loads `librocm_smi64.so`.
- `rocprof` is the tool (and a Bash script) of ROC Profiler, which seems to use a library called `librocprofiler64.so`.
- Both are included in ROCm installation.
- `rocm_smi.h` offers a `rsmi_gpu_metrics_t` which provides a limited set of metrics such as activity of the SMs, frequencies, temperature an PCI-E speeds.

## ROCm (library)


## ROC Profiler (tool)

[ROC Profiler] (https://github.com/ROCm-Developer-Tools/rocprofiler) is used to access to hardware counters.

AMD GPUPerfApi seems also an old CUPTI equivalent.