#include "GuiziOS.hpp"

void abort() {
	printf("kernel: panic: abort()\n");
	while (1) { }
}