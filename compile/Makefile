CC:=i686-elf-gcc
AS:=i686-elf-as
WARNINGS:=-Wall -Wextra
CFLAGS:=-std=gnu99 -ffreestanding -O2 $(WARNINGS) -I../include/
OBJDIR:=obj/
SOURCEDIR:=../src
SOURCES:=$(shell find $(SOURCEDIR) -name '*.c') $(shell find $(SOURCEDIR) -name '*.S')
OBJECTS:=$(SOURCES:../src/%.c=%.o) $(SOURCES:../src/%.S=%.o)

iso: bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir

bin: source linker.ld
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib $(OBJDIR)multiboot.o $(OBJDIR)kernel_entry.o $(OBJDIR)port.o $(OBJDIR)vga.o -lgcc

source: $(OBJECTS)

%.o : ../src/%.c
	mkdir -p obj
	$(CC) -c $(CFLAGS) $< -o obj/$@

%.o : ../src/%.S
	mkdir -p obj
	$(AS) $< -o obj/$@

clean:
		rm -f *.o
		rm -f *.bin
		rm -f *.iso
		rm -rf isodir
		rm -rf obj

qemu: iso
	qemu-system-i386 kernel.iso
