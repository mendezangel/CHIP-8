#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>
#include <stdbool.h>

#define MEMORY_SIZE 4096
#define REGISTER_COUNT 16
#define STACK_SIZE 16
#define KEY_COUNT 16
#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define START_ADDRESS 0x200
#define FONTSET_START_ADDRESS 0x50
#define FONTSET_SIZE 80

typedef struct {
  uint8_t memory[MEMORY_SIZE];        // 4KB memory
  uint8_t V[REGISTER_COUNT];          // 16 registers (V0-VF)
  uint16_t I;                         // Address register
  uint16_t pc;                        // Program counter
  uint8_t sp;                         // Stack pointer
  uint16_t stack[STACK_SIZE];         // Stack
  uint8_t delay_timer;                // Delay timer
  uint8_t sound_timer;                // Sound timer
  uint8_t keypad[KEY_COUNT];          // Keypad state
  uint32_t display[DISPLAY_HEIGHT][DISPLAY_WIDTH]; // Display buffer
  uint16_t opcode;
  bool draw_flag;                                    // Flag to indicate screen update needed 
} Chip8;

// Initialize Chip8 record.
// Parameters:
//  - Chip *chip8: pointer to chip8 record.
void chip8_init(Chip8 *chip8);

// Load rom into TODO loading into what again?
bool chip8_load_rom(Chip8 *chip8, const char* filename);

// TODO: function description
void chip8_cycle(Chip8* chip8);

// TODO: function description
void chip8_update_timers(Chip8* chip8);

#endif
