#ifndef _KERNEL_HPP_
#define _KERNEL_HPP_
#include "GuiziOS.hpp"
#include "Terminal.hpp"

class Kernel {
public:
    Kernel();
    ~Kernel();

    inline void write_io(uint16_t port, uint8_t val);
    inline uint8_t read_io(uint16_t port);
    void run();
    
private:
    const Terminal *terminal;
};

#endif