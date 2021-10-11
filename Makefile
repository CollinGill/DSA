TARGET = out
CFLAGS = -Wall -Wextra -Werror -pedantic
CC = gcc
SRC := $(wildcard *.c)
OBJ = $(SRC:.c=.o)
INC := $(wildcard include/*.h)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	clear

%.o: %.c $(INC)
	$(CC) -c $<

clean:
	rm $(TARGET) $(OBJ)
	clear
