CC=i686-elf-gcc
AS=i686-elf-as
WARNINGS:= -Wall -Wextra
CFLAGS := -std=gnu99 -ffreestanding -O2 $(WARNINGS)

iso: bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir

bin: source linker.ld
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib multiboot.o kernel_entry.o port.o vga.o -lgcc

source: kernel_entry.o multiboot.o port.o vga.o

vga.o: ../vga.c
	$(CC) -c ../vga.c -o vga.o $(CFLAGS)

port.o: ../port.c
	$(CC) -c ../port.c -o port.o $(CFLAGS)

kernel_entry.o: ../kernel_entry.c
	$(CC) -c ../kernel_entry.c -o kernel_entry.o $(CFLAGS)

multiboot.o: ../multiboot.S
	$(AS) ../multiboot.S -o multiboot.o

clean:
		rm -f *.o
		rm -f *.bin
		rm -f *.iso
		rm -rf isodir

qemu: iso
	qemu-system-i386 kernel.iso
