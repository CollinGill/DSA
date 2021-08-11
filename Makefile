CC = gcc
CFLAGS = -Wall
LDFAGS = 
SRCFILES := $(wildcard ./src/*.c)
OBJFILES := $(SRCFILES:.c=.o)
TARGET = out

all: $(TARGET)

clean: 
	rm -f $(OBJFILES) $(TARGET) *~