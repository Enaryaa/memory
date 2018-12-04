
#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

#define longueurImage 60;
#define largeurImage 50;

struct card
{
  char sprite[20];
  int x;
  int y;
  int isReturned;
};

int main(int argc, char * argv[]){ 

/*ces valeurs ici on été ajouté pour l'exemple , il fautdra placer les 24 sprites*/
char sprite[4][50] = { "coeur", "pique", "carreau", "trefle" };

/* liste aleatoire ICI il faut que ce tableau soit généré aleatoirement avec chaque carte en deux exemplaire*/
char randomize[8][50] = {"coeur", "pique", "coeur", "trefle", "carreau", "trefle", "carreau", "pique"}

  /* rappel : ne pas oublier de définir la constante des longueurs d'image*/
  /*struct card heart = {"heart.png", 10, 20, 0};*/
  /*ici on applique une marge pour afficher une belle grille avec les images*/
  int marge = 4;
  /*ici on défini la première position x*/
  int x = marge;
  /*de même pour y*/
  int y = marge;

  int ligne =  cartex;
  int colonne =  cartey;

  /* ce tableau doit être rempli grace au tableau randomize pour chaque carte
  struct card tableau[8][6];
  /*on défini une cle pour pour recuperer le sprite de la liste aleatoire,
   il sera incrmenté dans la seoncde boucle for*/
 

  int random = 0;
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 6; ++j)
    {
      tableau[i][j] = {randomize[random], x, y, 0};
      x = x + marge + longueurImage;
      y = y + marge + largeurImage;
      random = random + 1;
      /*a ce moment là, on peut afficher les images mais face caché*/
    }
  }



return EXIT_SUCCESS;
}

