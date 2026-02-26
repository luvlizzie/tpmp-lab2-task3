# Makefile for tpmp-lab2-task3
# Author: Kudinova Elizaveta, group 12

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
TARGET = bin/task3_program
OBJDIR = obj
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Create target directory
$(TARGET): $(OBJECTS) | bin
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile .c files to .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory
bin:
	mkdir -p bin

# Create obj directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean build files
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rmdir $(OBJDIR) 2>/dev/null || true

# Run the program
run: $(TARGET)
	./$(TARGET)

# Check target for GitHub Actions
check: $(TARGET)
	./$(TARGET)

# Distcheck target for GitHub Actions
distcheck: clean check

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  run      - Build and run the program"
	@echo "  check    - Run the program (for GitHub Actions)"
	@echo "  distcheck- Clean, build and run"
	@echo "  help     - Show this help"

.PHONY: all clean run check distcheck help
