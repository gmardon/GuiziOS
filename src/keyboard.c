#include "keyboard.h"

uint8_t readkey()
{
    if(readio(0x64) & 1)
		return readio(0x60);
    return (0);
}

char keytoascii(uint8_t key)
{
    return 'c';
}

void keyboard_init()
{
    
}