# Kernel Project
This is a kernel project that uses a multiboot header to boot, instead of a custom bootloader

# Compiling
To build the kernel.bin, i686-elf-gcc and the i686-elf binutils are required. To build the ISO, grub, mtools, and xorriso are required. The Makefile can be found in the `compile/` directory.

To build the full ISO, run `make`

To build just the binary file, run `make kernel.bin`

To autolaunch the kernel in an emulator after build:
* With QEMU: `make qemu`
* With bochs: `make bochs`

# Feature List
So far, the kernel has the following features implemented:
* Printing to VGA memory
* Reading a Multiboot memory map
* Set up required GDT descriptors:
    * Kernel Code
    * Kernel Data
    * User Code
    * User Data
    * Null Segment
* Setup IDT structure
    * Handlers for reserved interrupts
    * Handlers for 16 IRQs
* Configure PIC
    * Ability to set/clear IRQs
    * Remapped IRQs to IDT entries 32-47
* Configure PIT
    * Interval can be set in terms of milliseconds 
