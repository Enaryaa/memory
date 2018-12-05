#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

#define longueurImage 256
#define largeurImage 256


/* charger tous les sprites au debut afin d'avoir des identifiants pour chaque sprite -> avoir des int 
à la place des char et avec le pointeur, savoir si on clique sur les memes cartes quand on les retourne 
(condition de victoire) */

struct card
{
  char sprite[20];
  int x;
  int y;
  int isReturned;
};

int main(int argc, char * argv[]){ 

  /*ces valeurs ici on été ajouté pour l'exemple , il fautdra placer les 24 sprites*/
  char sprite[4][50] = { "cards-club.png", "cards-diamond.png", "cards-heart.png", "cards-spade.png" };

  /* liste aleatoire ICI il faut que ce tableau soit généré aleatoirement avec chaque carte en deux exemplaire*/
  char randomize[8][50] = {"./cards-heart.png", "./cards-club.png", "cards-heart.png", "cards-spade.png", "cards-diamond.png", "cards-spade.png", "cards-diamond.png", "cards-club.png"};

  /* rappel : ne pas oublier de définir la constante des longueurs d'image*/
  /*struct card heart = {"heart.png", 10, 20, 0};*/
  /*ici on applique une marge pour afficher une belle grille avec les images*/
  int marge = 4;
  /*ici on défini la première position x*/
  int x = marge;
  /*de même pour y*/
  int y = marge;

  /* ce tableau doit être rempli grace au tableau randomize pour chaque carte */
  struct card tableau[5][3];
  /*on défini une cle pour pour recuperer le sprite de la liste aleatoire,
   il sera incrmenté dans la seoncde boucle for*/
  InitialiserGraphique();
  CreerFenetre(10,10,(longueurImage*4 + marge*4 + 4),(largeurImage*2 + marge*2 +4));

  int random = 0;
  int i, j;
  for ( i = 0; i < 2; i++)
  {    
    for ( j = 0; j < 4; j++)
    {
      struct card current = { "", x, y, 0 };
      tableau[i][j] = current;
      DessinerRectangle(x, y,longueurImage, largeurImage);
      int sprite = ChargerSprite(randomize[random]);
      AfficherSprite(sprite, x, y);
      
      /*ChargerImage(randomize[random], x, y, x + longueurImage, y + largeurImage, longueurImage, largeurImage);*/
      x = x + marge +longueurImage;
      random = random + 1;
      /*a ce moment là, on peut afficher les images mais face caché*/
    }
    x = marge; 
    y = y + marge + largeurImage;
  }


  FermerGraphique();

  return EXIT_SUCCESS;
}

