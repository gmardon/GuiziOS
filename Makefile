SRC_ASM				= 		asm/boot.asm

SRC_KERNEL			=		src/main.cpp		\
							src/Kernel.cpp		\
							src/Keyboard.cpp 	\
							src/libcpp/memset.cpp \
							src/libcpp/printf.cpp \
							src/libcpp/strlen.cpp \
							src/libcpp/putchar.cpp \

OBJ_ASM				=		$(SRC_ASM:asm/%.asm=bin/%.o)

OBJ_KERNEL			=		$(SRC_KERNEL:src/%.cpp=bin/%.o)

CPPFLAGS			=		-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -I./include/

all:			kernel asm
				./toolchain/cross/x86_64/bin/i686-elf-gcc -T link.ld -o bin/GuiziOS -ffreestanding -O2 -nostdlib $(OBJ_KERNEL) $(OBJ_ASM) -lgcc

kernel:			$(OBJ_KERNEL) 
#				./toolchain/cross/x86_64/bin/i686-elf-g++ -c $(SRC_KERNEL) -o $(OBJ_KERNEL) $(CPPFLAGS) 

asm:			$(OBJ_ASM)
#				./toolchain/cross/x86_64/bin/i686-elf-as $(SRC_ASM) -o $(OBJ_ASM)

bin/%.o: src/%.cpp
				./toolchain/cross/x86_64/bin/i686-elf-g++ -c $< -o $@ $(CPPFLAGS) 

bin/%.o: asm/%.asm
				./toolchain/cross/x86_64/bin/i686-elf-as $< -o $@ $(OBJ_ASM)
clean:
				rm -rf $(OBJ_ASM)
				rm -rf $(OBJ_KERNEL)

fclean:			clean
				rm -rf bin/GuiziOS

re:			fclean all
.PHONY:		all clean fclean re asm kernel