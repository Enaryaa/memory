#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

#define longueurImage 95
#define largeurImage 95

int goon = 0;
/* charger tous les sprites au debut afin d'avoir des identifiants pour chaque sprite -> avoir des int 
à la place des char et avec le pointeur, savoir si on clique sur les memes cartes quand on les retourne 
(condition de victoire) */

struct card
{
 /* int id;*/
  char sprite[24];
  int x;
  int y;
  int isReturned;
};

int main(int argc, char * argv[]){ 

  /*ces valeurs ici on été ajouté pour l'exemple , il fautdra placer les 24 sprites*/
  char sprite[4][24] = { "./carte1.png", "./carte2.png", "./carte3.png", "./carte4.png"};

  /* liste aleatoire ICI il faut que ce tableau soit généré aleatoirement avec chaque carte en deux exemplaire*/
  char randomize[8][50] = {"./carte1.png", "./carte2.png", "./carte3.png", "./carte4.png" "./carte1.png", "./carte2.png", "./carte3.png", "./carte4.png"};

  /* rappel : ne pas oublier de définir la constante des longueurs d'image*/
  /*struct card heart = {"heart.png", 10, 20, 0};*/
  /*ici on applique une marge pour afficher une belle grille avec les images*/
  int marge = 20;
  /*ici on défini la première position x*/
  int x = marge;
  /*de même pour y*/
  int y = marge;

  /* ce tableau doit être rempli grace au tableau randomize pour chaque carte */
  struct card tableau[5][3];
  /*on défini une cle pour pour recuperer le sprite de la liste aleatoire,
   il sera incrmenté dans la seoncde boucle for*/
  InitialiserGraphique();
  CreerFenetre(300,300,(longueurImage*4 + marge*4 + 20),(largeurImage*2 + marge*2 +20));

  int random = 0;
  int i, j;

  while(!SourisCliquee()){

  for ( i = 0; i < 2; i++)
  {    
    for ( j = 0; j < 4; j++)
    {
      struct card current = {"", x, y, 0 };
      tableau[i][j] = current;
      DessinerRectangle(x, y,longueurImage, largeurImage);
      int sprite = ChargerSprite(randomize[random]);
      AfficherSprite(sprite, x, y);
      
      /*ChargerImage(randomize[random], x, y, x + longueurImage, y + largeurImage, longueurImage, largeurImage);*/
      x = x + marge +longueurImage;
      random = random + 1;
      /*a ce moment là, on peut afficher les images mais face caché*/
      
      if((SourisCliquee()) &&(_X >= marge) && (_X <= longueurImage + marge) && (_Y >= marge) && (_Y <= largeurImage + marge)){
          RemplirRectangle(x, y,longueurImage, largeurImage);
         
    }
    x = marge; 
    y = y + marge + largeurImage;
  }


      }
    
}


Touche();
FermerGraphique();

  return EXIT_SUCCESS;
}
