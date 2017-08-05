#ifndef _KERNEL_HPP_
#define _KERNEL_HPP_
#include "GuiziOS.h"

void writeio(uint16_t port, uint8_t val);
uint8_t readio(uint16_t port);

#endif