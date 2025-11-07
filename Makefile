CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lSDL2

SRC = src/main.c src/chip8.c src/display.c src/input.c
OBJ = $(SRC:.c=.0)
	TARGET = chip8

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -P $(TARGET) $(LIBS)

clean:
	rm -f $(OBJ) $(TARGET)
