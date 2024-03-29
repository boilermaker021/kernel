CC:=i686-elf-gcc
AS:=i686-elf-as
WARNINGS:=-Wall -Wextra
CFLAGS:=-std=gnu99 -ffreestanding -O2 $(WARNINGS) -I../include/
OBJDIR:=obj
SOURCEDIR:=../src
SUBDIRS:=$(shell find $(SOURCEDIR) -type d)
BUILDDIRS:=$(SUBDIRS:$(SOURCEDIR)%=$(OBJDIR)%)
CSOURCES:=$(shell find $(SOURCEDIR) -name '*.c') 
ASSOURCES:=$(shell find $(SOURCEDIR) -name '*.S')
OBJECTS:=$(CSOURCES:../src/%.c=$(OBJDIR)/%.o) $(ASSOURCES:../src/%.S=$(OBJDIR)/%.o)

kernel.iso: kernel.bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir

kernel.bin: $(OBJECTS) linker.ld
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib $(OBJECTS) -lgcc -Xlinker -Map=kernel.map


$(OBJDIR)/%.o : ../src/%.c
	mkdir -p $(BUILDDIRS)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/%.o : ../src/%.S
	mkdir -p $(BUILDDIRS)
	$(AS) $< -o $@

clean:
		rm -f *.o
		rm -f *.bin
		rm -f *.iso
		rm -rf isodir
		rm -rf obj
		rm -f kernel.map
		rm bochslog*
		rm bx_enh_dbg.ini

qemu: kernel.iso
	qemu-system-i386 -m 4G -boot d -cdrom kernel.iso

bochs: kernel.iso
	mkdir -p bochs
	bochs -f bochscfg.txt -q
