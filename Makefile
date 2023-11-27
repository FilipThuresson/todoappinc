CC = gcc
CFLAGS = -Wall -Werror -g

SRC = main.c ui.c io.c

HEADERS = ui.h io.h

OBJ = $(SRC:.c=.o)

all: main
	clear && ./main
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c $(HEADERS) clean
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main $(OBJ)