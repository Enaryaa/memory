CC=gcc
ARGS=-lgraph
EXEC=grille

all: $(EXEC)

grille: grille.o main.o
		$(CC) -o grille grille.o main.o $(ARGS)

grille.o: grille.c
		$(CC) -o grille.o -c grille.c $(ARGS)

main.o: main.c grille.h 
		$(CC) -o main.o -c main.c $(ARGS)

clean:
		rm -rf *.o

rm: clean
		rm -rf $(EXEC)
