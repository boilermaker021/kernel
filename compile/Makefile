CC:=i686-elf-gcc
AS:=i686-elf-as
WARNINGS:=-Wall -Wextra
CFLAGS:=-std=gnu99 -ffreestanding -O2 $(WARNINGS) -I../include/
OBJDIR:=obj
SOURCEDIR:=../src
CSOURCES:=$(shell find $(SOURCEDIR) -name '*.c') 
ASSOURCES:=$(shell find $(SOURCEDIR) -name '*.S')
OBJECTS:=$(CSOURCES:../src/%.c=%.o) $(ASSOURCES:../src/%.S=%.o)

iso: bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir

bin: source linker.ld
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib $(OBJECTS:%=$(OBJDIR)/%) -lgcc

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
