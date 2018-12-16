#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<graph.h>
#include<time.h>
#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L

int main(void/*int cartex, int cartey*/)
{

  srand(time(NULL));

  int seconde = 0; 
  char buf[100];
  /*initialise seconde à 0 pour commencer le temps à partir de 0*/
  unsigned long temps;

  int goon = 1;

  

  int cartex = 4,
  cartey = 5,
  spriterandsize = cartex * cartey,/*ça il a dit que ça ne servait a rien de le faire comme ça, il vaut mieux mettre directement les valeurs comme on connait d'avance la taille du tableau*/
  spritesize = spriterandsize/2,/*suite à au-dessus : Il préfère qu'on utilise préfère pas de nom full Majuscule et "_" pour les noms de variables*/
  MAX = spriterandsize,
  MIN = 0,
  marge = 40, 
  x = marge,
  y = 70,
  i, 
  j;

  temps = Microsecondes() + CYCLE;

  InitialiserGraphique();
  CreerFenetre(10,25,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55));
  ChargerImageFond("../Image/fond.png");


    int sprite[10] = {  /*créer le tableau contenant les sprites*/
    ChargerSprite("../Image/carte1.png"),
    ChargerSprite("../Image/carte2.png"),
    ChargerSprite("../Image/carte3.png"),
    ChargerSprite("../Image/carte4.png"),
    ChargerSprite("../Image/carte5.png"),
    ChargerSprite("../Image/carte6.png"),
    ChargerSprite("../Image/carte7.png"),
    ChargerSprite("../Image/carte8.png"),
    ChargerSprite("../Image/carte9.png"),
    ChargerSprite("../Image/carte10.png"),
    };

    int sprite2 = ChargerSprite("../Image/back.png");

    int spritesRand[spriterandsize]; /*tableau destiné a accueillir les valeurs random de sprite*/
    
    for (i = 0; i < spriterandsize; i ++)
    {     /*incremente le tableau random de 0*/
      
      spritesRand[i] = 0;
    }

    for (i = 0; i < spritesize; i++)
    {  /*boucle dans le tab des sprites pour garder le sprite courant*/
      int current = sprite[i];
      printf("sprite %d : %d\n", i, sprite[i] );


      for (j = 0; j < 2; ) {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
        
        int ran = (rand() % (MAX - MIN) + MIN);

        if (spritesRand[ran] == 0)
        {  /*le curseur cherche aléatoirement un espace dans le tab*/
           
          spritesRand[ran] = current;

          j++;
        }
      }
    }


    int grillerand[4][5];

    int ligne, colonne;
    i = 0;

    for ( ligne = 0; ligne < 4; ligne++ )
    {

      for (colonne = 0; colonne < 5; colonne++)
      {

        grillerand[ligne][colonne] = spritesRand[i];

        AfficherSprite(sprite2, x, y);

        x = x + marge + longueurImage;

        i++;
      }

      x = marge;

      y = y + marge + largeurImage;

    }

    int selection = 0, score = 0, selectionx = 0, selectiony = 0, ecran = 0;

    while (goon == 1)
    {
 
    if (Microsecondes()>temps)
    {
      seconde++;
      
      ChoisirEcran(1);
      EffacerEcran(CouleurParNom("White"));
      ChargerImageFond("../Image/fond.png");
      snprintf(buf,100,"temps : %5d",seconde);
      EcrireTexte(70,30,buf,1);
      CopierZone(1,0,0,0,500,70,0,0);
      ChoisirEcran(0);
  
      printf("%d\n", seconde);
      temps = Microsecondes() + CYCLE;
    }

    int i =0;
    x = marge;
    y = 70;

    if(SourisCliquee())
    {


      for(ligne = 0; ligne < 4; ligne++ )
      {
      
        for(colonne = 0; colonne < 5; colonne++)
        {
          
          if ((_X >= x) && (_X <= x + longueurImage) && (_Y >= y) && (_Y <= y + largeurImage))
          {
            AfficherSprite(spritesRand[i],x, y);
            sleep(1); /*mise en veille du programme de 1sec pour la seconde selection, permet de le voir*/
            printf("clique %d,%d : %d\n", x, y, spritesRand[i] );
            if(selection == 0){ /*stocke la valeur du clique dans selection, ses coordonnées dans selectionx et selectiony*/
              selection = spritesRand[i];
              selectionx = x;
              selectiony = y;
            }
            else {
              if(selection == spritesRand[i] && (selectionx != x || selectiony != y) ){ /*si le second clique rempli ses conditions alors on a trouvé une paire*/
                  score++;  /*le score s'incrémente jusqu'a avoir trouvé les 10paires (ici) donc si score == 10, goon = 0 (voir plus bas) */
                  printf("Goal !, score : %d\n", score);
              }
              else {
                printf("Wrong\n");
               
                AfficherSprite(sprite2, x, y);  /*si faux, réaffiche le bac par dessus la premi!re selection et la deuxeieme*/
                AfficherSprite(sprite2, selectionx, selectiony);
              }
              selection = 0; /*rénitialise les valeurs */
              selectionx = 0; 
              selectiony = 0;
            }
          }
          x = x + marge + longueurImage;
          i++;
        }
        x = marge;
        y = y + marge + largeurImage;
      }
    } 
    if(score == 10){ /* condition de victoire, return 0 pour montrer la fin*/
      goon = 0;
      return 0;
    }

    while (ToucheEnAttente()){ /*cheatmode, si on clique sur t affiche les cartes retournées*/
      ChoisirEcran(2);
      ChargerImageFond("../Image/fond.png");
       i = 0;

        for ( ligne = 0; ligne < 4; ligne++ )
        {

          for (colonne = 0; colonne < 5; colonne++)
          {

            AfficherSprite(spritesRand[i], x, y);

            x = x + marge + longueurImage;

            i++;
          }

          x = marge;

          y = y + marge + largeurImage;

        }
      if (Touche() == XK_t){
        if (ecran == 0) {
          printf("screen cheat\n");
          ecran = 1;
          CopierZone(2,0,0,70,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55),0,70);
        } else {
          printf("screen game\n");
          ecran = 0;
          CopierZone(0,2,0,70,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55),0,70);
        }
      }
    }
  }
}