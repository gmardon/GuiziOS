#include "GuiziOS.h"

void abort() {
	printf("kernel: panic: abort()\n");
	while (1) { }
}