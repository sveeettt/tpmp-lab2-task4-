# Makefile для проекта tpmp-lab2-task4

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -Iinclude -g
SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/program

.PHONY: all clean run info directories

all: directories $(TARGET)

directories:
	@mkdir -p $(BINDIR) $(OBJDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "Сборка завершена. Исполняемый файл: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h | directories
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "Очистка выполнена."

run: $(TARGET)
	./$(TARGET)

info:
	@echo "Проект: tpmp-lab2-task4"
	@echo "Компилятор: $(CC)"
	@echo "Флаги: $(CFLAGS)"
	@echo "Исходники: $(SOURCES)"
