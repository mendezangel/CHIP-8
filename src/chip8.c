#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chip8.h"

static const uint8_t chip8_fontset[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void chip8_init(Chip8* chip8) {
    int i;

    // Zero out the entire struct
    memset(chip8, 0, sizeof(Chip8));

    // Set program counter to start address in memory.
    chip8->pc = START_ADDRESS; // e.g. 0x200
    
    // load fontset into memory
    for (i = 0; i < FONTSET_SIZE; i++) {
        chip8->memory[FONTSET_START_ADDRESS + i] = chip8_fontset[i];
    }
}

void chip8_cycle(Chip8* chip8) {
    /* Fetch opcode -> decode opcode -> execute opcode
     during this step, system fetches one opcode from memory at the location
     specified by the program counter (pc). Every cycle, this method is called which
     emulates one cycle of the chip 8 CPU. Emulator will fetch, decode, and execute one
     opcode.
    */
}

bool chip8_load_rom(Chip8 *chip8, const char *filename) {
    FILE *fp;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
      perror("Failed to open file");
      return false;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    
    // Check if ROM fits in available memory
    if (file_size > (MEMORY_SIZE - START_ADDRESS)) {
      fprintf(stderr, "ROM too large to fit into memory.\n");
      fclose(fp);
      return false;
    }

    // Read ROM directly into memory starting at START_ADDRESS
    size_t bytes_read = fread(&chip8->memory[START_ADDRESS], 1, file_size, fp);

    fclose(fp);

    if (bytes_read != file_size) {
      fprintf(stderr, "Failed to read entire ROM\n");
      return false;
    }

    return true;
}

void chip8_update_timers(Chip8* chip8) {
    // TODO: Implement
}
