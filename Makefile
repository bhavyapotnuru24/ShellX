CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = bin/shellx

SRC = src/main.c \
      src/modules/file_manager.c \
      src/modules/command_runner.c \
      src/modules/notes_manager.c \
      src/modules/calculator.c \
      src/modules/system_info.c \
      src/modules/password_generator.c \
      src/modules/interactive_shell.c \
      src/utils/ui.c \
      src/utils/logger.c \
      src/utils/validator.c

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
