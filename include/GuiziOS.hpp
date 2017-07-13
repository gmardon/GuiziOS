#ifndef _GUIZIOS_HPP_
#define _GUIZIOS_HPP_
#include <stdbool.h> 
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#define EOF (-1)

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

extern "C" {
    bool print(const char* data, size_t length);
    int printf(const char* format, ...);
    size_t strlen(const char* str);
    int putchar(int ic);
	void abort();
}
#endif