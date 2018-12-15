CC=gcc
ARGS=-lgraph
EXEC=grille

all: $(EXEC)

grille: grille.o menu.o
		$(CC) -o grille grille.o menu.o 

grille.o: grille.c
		$(CC) -o grille.o -c grille.c $(ARGS)

menu.o: menu.c grille.h 
		$(CC) -o menu.o -c menu.c $(ARGS)

clean:
		rm -rf *.o

rm: clean
		rm -rf $(EXEC)
