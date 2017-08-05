SRC_ASM				= 		asm/boot.asm		

SRC_KERNEL			=		src/main.c		\
							src/kernel.c	\
							src/keyboard.c 	\
							src/terminal.c 	\
                            src/libc/abort.c \
							src/libc/memset.c \
							src/libc/printf.c \
							src/libc/strlen.c \
							src/libc/putchar.c

OBJ_ASM				=		$(SRC_ASM:asm/%.asm=bin/%.o)

OBJ_KERNEL			=		$(SRC_KERNEL:src/%.c=bin/%.o)

CFLAGS			=		-ffreestanding -O2 -Wall -Wextra -I./include/ -std=gnu99 

all:			kernel asm
				./toolchain/cross/x86_64/bin/i686-elf-gcc -T link.ld -o bin/GuiziOS -nostdlib -nostartfiles -ffreestanding -O2 $(OBJ_KERNEL) $(OBJ_ASM) -lgcc

kernel:			$(OBJ_KERNEL) 
#				./toolchain/cross/x86_64/bin/i686-elf-g++ -c $(SRC_KERNEL) -o $(OBJ_KERNEL) $(CPPFLAGS) 

asm:			$(OBJ_ASM)
#				./toolchain/cross/x86_64/bin/i686-elf-as $(SRC_ASM) -o $(OBJ_ASM)

bin/%.o: src/%.c
				./toolchain/cross/x86_64/bin/i686-elf-gcc -c $< -o $@ $(CFLAGS) 

bin/%.o: asm/%.asm
				./toolchain/cross/x86_64/bin/i686-elf-as $< -o $@ $(OBJ_ASM)
clean:
				rm -rf $(OBJ_ASM)
				rm -rf $(OBJ_KERNEL)

fclean:			clean
				rm -rf bin/GuiziOS

re:			fclean all
.PHONY:		all clean fclean re asm kernel