CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lSDL2

# Main emulator
SRC = src/main.c src/chip8.c src/display.c src/input.c
OBJ = $(SRC:.c=.o)
TARGET = chip8

# Tests
TEST_SRC = tests/test_chip8.c src/chip8.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = test_chip8

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -P $(TARGET) $(LIBS)

# Test target - compiles without SDL
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_TARGET)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
