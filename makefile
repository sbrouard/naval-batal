############
# Makefile #
############

CC = gcc
CFLAGS = -Wall -std=c99 -O
LDFLAGS = -g
EXEC = bataille
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

bataille: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

afficher_grille.o: batal.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

placer_bateaux.o: batal.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: batal.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ) $(EXEC)
