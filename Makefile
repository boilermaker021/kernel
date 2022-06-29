kernel.bin: kernel_entry.o kernel.o port.o screen.o
	~/opt/cross/bin/i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

kernel_entry.o: kernel/kernel_entry.asm
	nasm $< -f elf -o $@

kernel.o: kernel/kernel.c
	~/opt/cross/bin/i686-elf-gcc -ffreestanding -c $< -o $@

port.o: kernel/drivers/port.c
	~/opt/cross/bin/i686-elf-gcc -ffreestanding -c $^ -o $@

screen.o: kernel/drivers/screen.c
	~/opt/cross/bin/i686-elf-gcc -ffreestanding -c $^ -o $@

bootsect.bin: boot/32bit_main.asm
	nasm $< -f bin -o $@

os-image.bin: bootsect.bin kernel.bin
	cat $^ > $@

run: os-image.bin
	qemu-system-x86_64 -fda $<

clean:
	rm *.bin *.o *.dis