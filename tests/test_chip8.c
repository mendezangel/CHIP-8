#include "../src/chip8.h"
#include <assert.h>
#include <stdio.h>

void test_chip8_init() {
    Chip8 chip8;
    chip8_init(&chip8);

    assert(chip8.pc == 0x200); // PC starts at 0x200
    assert(chip8.sp == 0);     // Stack pointer is 0
    assert(chip8.I == 0);      // Index register is 0

    // Check font is loaded
    assert(chip8.memory[FONTSET_START_ADDRESS] == 0xF0); // First byte of '0' character
    
    printf("test_chip8_init passed \n");
}

int main() {
    test_chip8_init();

    return 0;
}
