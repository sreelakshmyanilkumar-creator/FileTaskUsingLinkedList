# compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Target executable
TARGET = output/LinkedList

# Source files
SRCS = LinkedList.c ReadFile.c LlCreation.c
OBJS = $(patsubst %.c,output/%.o,$(SRCS))

# Default rule
all: $(TARGET)

#Link object files into final executable
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#compile each .c into .o
output/%.o: %.c Common.h ReadFile.h LlCreation.h | output
	$(CC) $(CFLAGS) -c $< -o $@

output:
	mkdir -p output

#clean up
clean:
	rm -rf output