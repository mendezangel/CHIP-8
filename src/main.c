// Entry point with game loop
#include <stdio.h>
#include "chip8.h"
#include "display.h"
#include "input.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <ROM file>\n", argv[0]);
    return 1;
  }

  Chip8 chip8;
  chip8_init(&chip8); //TODO: implement
  
  if (!chip8_load_rom(&chip8, argv[1])) { // TODO: implement
    printf("Failed to load ROM\n");
    return 1;
  }

  display_init(); // TODO: implement
  
  // Main emulation loop
  bool running = true;
  while (running) {
    // Execute one CPU cycle
    chip8_cycle(&chip8); // TODO: implement

    // Update timers
    chip8_update_timers(&chip8); // TODO: implement

    // Draw if needed
    if (chip8.draw_flag) {
      display_render(&chip8); // TODO: implement
      chip8.draw_flag = false;
    }

    // Handle input
    input_update(&chip8, &running); // TODO: implement
    
    // Delay to control speed (typically 500-700 Hz)
    SDL_Delay(2); // ~500 Hz (1000ms / 2ms = 500 cycles/sec)
  }
}
