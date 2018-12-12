#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L

int main(void) {
  srand(time(NULL));

const int SPRITE_SIZE = 10, 
SPRITE_RAND_SIZE = 20,  /*ou SPRITE_SIZE * 2 */
TWO_CARD = 2,
MAX = 20, 
MIN = 0;
int marge = 30; 
int x = marge;
int y = 70; 
int i, j;
int goon = 1;

InitialiserGraphique();
CreerFenetre(10,25,1200,700); 


int sprite[12] = {
ChargerSprite("../../Image/carte1.png"),
ChargerSprite("../../Image/carte2.png"),
ChargerSprite("../../Image/carte3.png"),
ChargerSprite("../../Image/carte4.png"),
ChargerSprite("../../Image/carte5.png"),
ChargerSprite("../../Image/carte6.png"),
ChargerSprite("../../Image/carte7.png"),
ChargerSprite("../../Image/carte8.png"),
ChargerSprite("../../Image/carte9.png"),
ChargerSprite("../../Image/carte10.png"),

};

int sprite2 = ChargerSprite("../../Image/back.png");

int spritesRand[SPRITE_RAND_SIZE];


 
  for (i = 0; i < SPRITE_RAND_SIZE; i ++) {     /*incremente le tableau random de 0*/
    spritesRand[i] = 0;
  }

  for (i = 0; i < SPRITE_SIZE; i++) {  /*boucle dans le tab des sprites pour garder le sprite courant*/
    /*printf("%d\n", i);*/
    int current = sprite[i];
    /*printf("%s\n", current);*/
    for (j = 0; j < TWO_CARD;) {	/*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
      int randKey = (rand() % (MAX - MIN) + MIN);
      /*printf("%d\n", randKey);
      printf("%s\n", spritesRand[randKey]);*/
      if (spritesRand[randKey] == 0) {	/*le curseur cherche aléatoirement un espace dans le tab*/
        spritesRand[randKey] = current;
        /*rintf("%s\n", spritesRand[randKey]);*/
        j++;
      }
    }
  }


int grillerand[4][5];

int ligne, colonne;
i = 0;

for ( ligne = 0; ligne < 4; ligne++ ){

  for (colonne = 0; colonne < 5; colonne++){

    grillerand[ligne][colonne] = spritesRand[i];

    AfficherSprite(sprite2, x, y);

    x = x + marge + longueurImage;

  }

  x = marge;

  y = y + marge + largeurImage;

}
 
while(goon == 1){

  if(SourisCliquee()){

    for(ligne = 0, x = 30; ligne < 4; ligne++ )
    {
      printf("%d ligne\n", ligne);
      i++;
      for(colonne = 0, y = 70; colonne < 5; colonne++)
      {
        printf("%d colonne\n", colonne);
        
        x = x + marge + longueurImage;

        i++;
        
        if ((_X >= x) && (_X <= x + longueurImage) && (_Y >= y) && (_Y <= y + largeurImage))
        {
          
          AfficherSprite(spritesRand[i],x, y);
          goon = 1;
          printf("why\n");
        }
       /* else if ((_X >= x) && (_X <= x + longueurImage) && (_Y >= y) && (_Y <= y + marge + largeurImage)){
*/
        }
       

      }
      x = marge;

      y = y + marge + largeurImage;

    }

  }
}



Touche();
FermerGraphique();



/* le premier for test toutes les valeurs de sprite[], à la position 0 il va entrer dans le 2e for
pour voir si le currentsprite a été placé 2x de facon aléatoire dans le tableau spriterand. 
alors si spriterand[ran] == NULL, ca veut dire quà la position ran du tableau (aléatoire), il est vide
et on va alors stocker le sprite courant une première fois. j s'incrémente car j compte le nombre de 
fois que le current sprite a été mis.
une fois j = 2, on sort de la boucle pr tester la seconde valeur du tebleau de sprite, et on refait la meme */

	 return EXIT_SUCCESS;
}