#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>


int main(void) {
  srand(time(NULL));

  const int SPRITE_SIZE = 4, 
    SPRITE_RAND_SIZE = 8,  /*ou SPRITE_SIZE * 2 */
    TWO_CARD = 2,
    MAX = 8, 
    MIN = 0;

  char *spriteOne = "../Image/carte1.png";
  char *spritetwo = "../Image/carte2.png";
  char *spriteThree = "../Image/carte3.png";
  char *spriteFour = "../Image/carte4.png";

  char *sprites[4] = {
    spriteOne, 
    spritetwo,
    spriteThree,
    spriteFour
  };


  char *spritesRand[SPRITE_RAND_SIZE];
  
  int i, j;
  for (i = 0; i < SPRITE_RAND_SIZE; i ++) {
    spritesRand[i] = NULL;
  }

  for (i = 0; i < SPRITE_SIZE; i++) {  /*boucle dans le tab des sprites pour garder le sprite courant*/
    /*printf("%d\n", i);*/
    char *current = sprites[i];
    /*printf("%s\n", current);*/
    for (j = 0; j < TWO_CARD;) {	/*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
      int randKey = (rand() % (MAX - MIN) + MIN);
      /*printf("%d\n", randKey);
      printf("%s\n", spritesRand[randKey]);*/
      if (spritesRand[randKey] == NULL) {	/*le curseur cherche aléatoirement un espace dans le tab*/
        spritesRand[randKey] = current;
        /*rintf("%s\n", spritesRand[randKey]);*/
        j++;
      }
    }
  }

  /*for (i = 0; i < SPRITE_RAND_SIZE; i ++) {
      printf("%s\n", spritesRand[i]);*/
  }


/* le premier for test toutes les valeurs de sprite[], à la position 0 il va entrer dans le 2e for
pour voir si le currentsprite a été placé 2x de facon aléatoire dans le tableau spriterand. 
alors si spriterand[ran] == NULL, ca veut dire quà la position ran du tableau (aléatoire), il est vide
et on va alors stocker le sprite courant une première fois. j s'incrémente car j compte le nombre de 
fois que le current sprite a été mis.
une fois j = 2, on sort de la boucle pr tester la seconde valeur du tebleau de sprite, et on refait la meme */

	 return EXIT_SUCCESS;
}