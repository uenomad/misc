### Context and command queues

The environment within which kernels execute and in which synchronization and memory management is defined.

The context includes:
- One or more devices
- Device memory
- One or more command-queues

All commands for a device (kernel execution, synchronization, and memory transfer operations) are submitted
through a command-queue. Each command-queue points to a single device within a context.


### The program object

The program object encapsulates:
- A context
- The program kernel source or binary
- List of target devices and build options

The C API build process to create a program object:
- clCreateProgramWithSource()
- clCreateProgramWithBinary()

OpenCL uses runtime compilation because in general you don’t know the details of the target device when you ship the program.

https://github.com/KhronosGroup/OpenCL-Guide