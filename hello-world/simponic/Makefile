.DEFAULT_GOAL := os.iso
.PHONY: demo

OBJECTS=entry.o kernel.o
KERNEL_BUILD_FLAGS=-std=c99 -ffreestanding -O0 -Wall -Wextra
OS_BUILD_FLAGS=-ffreestanding -O2 -nostdlib -lgcc

entry.o: boot.asm 
	nasm -felf32 boot.asm -o entry.o

kernel.o: kernel.c
	i386-elf-gcc -c kernel.c -o kernel.o $(KERNEL_BUILD_FLAGS)

os.bin: kernel.o entry.o
	i386-elf-gcc -T linker.ld -o os.bin $(OS_BUILD_FLAGS) $(OBJECTS)

os.iso: os.bin
	mkdir -p iso/boot/grub
	cp os.bin iso/boot/os.bin
	printf "menuentry 'HelloOS' {\n  multiboot /boot/os.bin\n  set gfxpayload=text\n}" > iso/boot/grub/grub.cfg
	grub-mkrescue -o os.iso iso

demo:
	qemu-system-i386 demo/os.iso

run: os.iso
	qemu-system-i386 os.iso

clean:
	rm -rf iso os.iso *.o *.bin
