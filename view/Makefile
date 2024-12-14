CC = gcc
CFLAGS = -I../model -I../controller -I../view

OBJ = view.o

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
