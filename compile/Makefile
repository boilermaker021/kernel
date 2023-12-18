CC=i686-elf-gcc
AS=i686-elf-as


kernel.iso: kernel.bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir

kernel.bin: source linker.ld
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib multiboot.o kernel_entry.o -lgcc

source: kernel_entry.o multiboot.o

kernel_entry.o: ../kernel_entry.c
	$(CC) -c ../kernel_entry.c -o kernel_entry.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

multiboot.o: ../multiboot.S
	$(AS) ../multiboot.S -o multiboot.o

clean:
		rm *.o
		rm *.bin
		rm *.iso

qemu: kernel.iso
	qemu-system-i386 kernel.iso
