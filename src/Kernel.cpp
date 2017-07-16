#include "Kernel.hpp"

Kernel Kernel::instance = Kernel();

inline void Kernel::write_io(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

inline uint8_t Kernel::read_io(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}


Kernel::Kernel() 
{
    this->terminal = Terminal();
    printf("[GuiziOS] Kernel is starting...\n");
}

Kernel::~Kernel() 
{
    
}

void Kernel::run()
{

}

Kernel& Kernel::Instance()
{
    return instance;
}