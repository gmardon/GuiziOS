all:
	./toolchain/cross/x86_64/bin/i686-elf-as asm/boot.asm -o bin/boot.o
	./toolchain/cross/x86_64/bin/i686-elf-g++ -c kernel.cpp -o bin/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	./toolchain/cross/x86_64/bin/i686-elf-gcc -T link.ld -o bin/GuiziOS -ffreestanding -O2 -nostdlib bin/boot.o bin/kernel.o -lgcc
