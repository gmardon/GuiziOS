#include "Terminal.hpp"

uint8_t Terminal::vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
uint16_t Terminal::vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

Terminal::Terminal() 
{
    this->row = 0;
	this->column = 0;
	this->color = this->vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	this->buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			size_t index = y * VGA_WIDTH + x;
			this->buffer[index] = this->vga_entry(' ', this->color);
		}
	}
}

Terminal::~Terminal()
{

}

void Terminal::setColor(uint8_t color)
{
    this->color = color;
}


void Terminal::setCharAt(char character, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	buffer[index] = this->vga_entry(character, color);
}

void Terminal::append(char character) 
{
	setCharAt(character, color, column, row);
	if (++this->column == VGA_WIDTH) {
		this->column = 0;
		if (++this->row == VGA_HEIGHT)
			this->row = 0;
	}
}