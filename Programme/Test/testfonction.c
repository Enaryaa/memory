#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L
#define marge 40


int i, j, ligne, colonne,x, y = 70, goon = 1;

int grille(int cartex, int cartey) {

srand(time(NULL));

int SPRITE_RAND_SIZE = cartex * cartey,
SPRITE_SIZE = SPRITE_RAND_SIZE/2,
MAX = SPRITE_RAND_SIZE,
MIN = 0;

int grillerand[cartex][cartey];

InitialiserGraphique();
CreerFenetre(10,25,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55));
ChoisirEcran(0);
ChargerImageFond("../../Image/fond.png");

int sprite[10] = {  /*créer le tableau contenant les sprites*/
ChargerSprite("../../Image/carte1.png"),
ChargerSprite("../../Image/carte2.png"),
ChargerSprite("../../Image/carte3.png"),
ChargerSprite("../../Image/carte4.png"),
ChargerSprite("../../Image/carte5.png"),
ChargerSprite("../../Image/carte6.png"),
ChargerSprite("../../Image/carte7.png"),
ChargerSprite("../../Image/carte8.png"),
ChargerSprite("../../Image/carte9.png"),
ChargerSprite("../../Image/carte10.png")
};

int sprite2 = ChargerSprite("../../Image/back.png");

int spritesRand[SPRITE_RAND_SIZE]; /*tableau destiné a accueillir les valeurs random de sprite*/
  
  for (i = 0; i < SPRITE_RAND_SIZE; i ++) {     /*incremente le tableau random de 0*/
    
    spritesRand[i] = 0;
  }

  for (i = 0; i < SPRITE_SIZE; i++) {  /*boucle dans le tab des sprites pour garder le sprite courant*/
    int current = sprite[i];

    for (j = 0; j < 2; ) {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
      
      int ran = (rand() % (MAX - MIN) + MIN);

      if (spritesRand[ran] == 0) {  /*le curseur cherche aléatoirement un espace dans le tab*/
         
         spritesRand[ran] = current;

         j++;
      }
    }
  }

i = 0;

for ( ligne = 0; ligne < cartex; ligne++ ){

  for (colonne = 0; colonne < cartey; colonne++){

    grillerand[ligne][colonne] = spritesRand[i];

    AfficherSprite(sprite2, x, y);

    x = x + marge + longueurImage;

    i++;
  }

  x = marge;

  y = y + marge + largeurImage;

}
return i;
}

 void clique(spritesRand, cartex, cartey, i){

while(goon == 1){


  if(SourisCliquee()){

    for(ligne = 0; ligne < cartex; ligne++ )
    {
    
      for(colonne = 0; colonne < cartey; colonne++)
      {
        
        if ((_X >= x) && (_X <= x + longueurImage) && (_Y >= y) && (_Y <= y + largeurImage))
        {
          
          AfficherSprite(spritesRand[i],x, y);
          goon = 1;
        }
        x = x + marge + longueurImage;
        i++;

      }
      x = marge;
      y = y + marge + largeurImage;

    }

  }

  /*if (ToucheEnAttente()){
    if (Touche() == XK_t){
        ChoisirEcran(1);
        ChargerImageFond("../Image/fond.png");
        CopierZone(0,1,0,0,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55),0,0);
        ChoisirEcran(1);

        AfficherSprite(spritesRand[i], x, y);
  }
}*/
}
}


int main(void){

grille(4,5);
clique();




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