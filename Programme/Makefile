CC=gcc
ARGS=-lgraph
EXEC=memory
CFLAGS=-g

all: $(EXEC)

memory: grille.o main.o
		$(CC) $(CFLAGS) -o memory grille.o main.o $(ARGS)

grille.o: grille.c
		$(CC) $(CFLAGS) -o grille.o -c grille.c 

main.o: main.c grille.h 
		$(CC) $(CFLAGS) -o main.o -c main.c 

run : 
	./$(EXEC)

./ : run 
		./$(EXEC)


clean:
		rm -rf *.o

rm: clean
		rm -rf $(EXEC)
