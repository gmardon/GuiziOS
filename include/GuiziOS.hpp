#ifndef _GUIZIOS_HPP_
#define _GUIZIOS_HPP_
#include <stdbool.h> 
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#define EOF (-1)
#define NULL 0

extern "C" {
    bool print(const char* data, size_t length);
    int printf(const char* format, ...);
    size_t strlen(const char* str);
    int putchar(int ic);
	void abort();

    
}

#endif