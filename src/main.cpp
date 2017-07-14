#include "Kernel.hpp"

Kernel *kernel;

extern "C" void main(void) {
    kernel = new Kernel();
    kernel->run();
}
