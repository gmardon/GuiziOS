#ifndef _TERMINAL_HPP_
#define _TERMINAL_HPP_
#include "GuiziOS.hpp"

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

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

class Terminal {
public:
    Terminal();
    ~Terminal();

    void setColor(uint8_t color);
    void append(char character);
	void write(char *str);
    void setCharAt(char character, uint8_t color, size_t x, size_t y);
private:
    size_t row;
    size_t column;
    uint8_t color;
    uint16_t* buffer;
	static uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);
	static uint16_t vga_entry(unsigned char uc, uint8_t color);
};
#endif