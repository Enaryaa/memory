#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

#define longueurImage 95
#define largeurImage 95
#define CYCLE 100000L

int goon = 0;
int cartex = 8;
int cartey = 6;
/* charger tous les sprites au debut afin d'avoir des identifiants pour chaque sprite -> avoir des int 
à la place des char et avec le pointeur, savoir si on clique sur les memes cartes quand on les retourne 
(condition de victoire) */
void timer(void)
    {
 
unsigned long Microsecondes(), temps;
char buf[100];
int seconde;
int go_on == 0;

InitialiserGraphique();   /*créer la fenetre */
CreerFenetre(200,190,1280,720);

temps = Microsecondes() + CYCLE;

while (go_on = 0)
{
  
if (Microsecondes()>temps){
seconde++; 
temps = (Microsecondes()+CYCLE);
snprintf(buf,100,"temps : %d",seconde);
        }
      }

    }

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
  struct card tableau[8][6];
  /*on défini une cle pour pour recuperer le sprite de la liste aleatoire,
   il sera incrmenté dans la seoncde boucle for*/
  InitialiserGraphique();
  CreerFenetre(200,200,(longueurImage*8 + marge*8 + 40),(largeurImage*6 + marge*6 +40));
  timer();
  int random = 0;
  int i, j;



  for ( i = 0; i < 6; i++)
  {    
    for ( j = 0; j < 8; j++)
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
    }
    x = marge; 
    y = y + marge + largeurImage;
  }



Touche();
FermerGraphique();

  return EXIT_SUCCESS;
}
