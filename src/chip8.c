#include "chip8.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void chip8_init(Chip8* chip8) {
    // Zero out the entire struct
    memset(chip8, 0, sizeof(Chip8));
    chip8->pc = START_ADDRESS;
}

void chip8_cycle(Chip8* chip8) {
    /* Fetch opcode -> decode opcode -> execute opcode
     during this step, system fetches one opcode from memory at the location
     specified by the program counter (pc).
    */
}
