## Hypervisor
Also called virtual machine monitor (VMM), is a software that runs in the host system (the base system), executes virtual machines and isolates its environments. An hypervisor runs in root mode.

## QEMU
QEMU is an open source machine emulator and virtualizer.  The most common is for “system emulation”, where it provides a virtual model of an entire machine (CPU, memory and emulated devices) to run a guest OS. In this mode the CPU may be fully emulated, or it may work with a hypervisor such as KVM to allow the guest to run directly on the host CPU. A virtual machine in user mode.

## KVM
Is the Linux hypervisor, in form of a kernel module or driver (kvm.ko), responsable for assign resources. It exposes the `/dev/kvm` interface, which a user mode virtual machine can use to setup its address space, feed the I/O and map the guest's video display. 

## Intel VT-x and AMD-V
CPU instructions for VM instances. Before give the control to the guest OS, the hypervisor executes some instructions (like VMXON and VMLAUNCH) to prepare the CPU to the non-root virtual instance code. When the virtual machine code executes a privileged function, it causes a VM-exit and the hypervisor gains the control, do what it has to do and resumes the execution in user mode. This is key for virtualization.

The reason how the hypervisor know why the VM exit happened and differences one VM instance from another is the VMCS (Virtual Machine Control Structure), which is a 4KiB (4*2^10 bytes) which contains this information.

## Yocto Project
Builds a customized Linux image. It can produce systems for different hardware platform. Is written in Python, and it uses a "recipe" system of `.bb` and `.bbappend` files.

## Docker

## OpenBMC

## RedFish

## Powerful links

https://binarydebt.wordpress.com/2018/10/14/intel-virtualisation-how-vt-x-kvm-and-qemu-work-together/

https://github.com/Wenzel/awesome-virtualization