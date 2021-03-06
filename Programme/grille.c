#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<graph.h>
#include<time.h>
#define longueurImage 95
#define largeurImage 95
#define marge 40
#define CYCLE 1000000L

void Grille(int cartex, int cartey)
{
  srand(time(NULL));
  /*initialise seconde à 0 pour commencer le temps à partir de 0*/
  int seconde = 0; 
  char buf[100];
  unsigned long temps;
  int goon = 1;
  int spriterandsize = cartex * cartey,
  spritesize = spriterandsize/2,
  MAX = spriterandsize,
  MIN = 0,
  x = marge,
  y = 70,
  i, 
  j;
  temps = Microsecondes() + CYCLE;
  /*(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55));*/
  ChargerImageFond("../Image/jeu2.png");

  int sprite[20] = {  
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
    ChargerSprite("../Image/carte11.png"),
    ChargerSprite("../Image/carte12.png"),
    ChargerSprite("../Image/carte13.png"),
    ChargerSprite("../Image/carte14.png"),
    ChargerSprite("../Image/carte15.png"),
    ChargerSprite("../Image/carte16.png"),
    ChargerSprite("../Image/carte17.png"),
    ChargerSprite("../Image/carte18.png"),
    ChargerSprite("../Image/carte19.png"),
    ChargerSprite("../Image/carte20.png")
  };

  int backcard = ChargerSprite("../Image/back.png");
  int spritesRand[40]; /*tableau destiné a accueillir les valeurs random de sprite*/
  
  for (i = 0; i < spriterandsize; i ++)
  {     /*incremente le tableau random de 0*/
    spritesRand[i] = 0;
  }

  for (i = 0; i < spritesize; i++)
  {  /*boucle dans le tab des sprites pour garder le sprite courant*/
    int current = sprite[i];
    for (j = 0; j < 2; )
    {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
      int ran = (rand() % (MAX - MIN) + MIN);
      if (spritesRand[ran] == 0)
      {  /*le curseur cherche aléatoirement un espace dans le tab*/
        spritesRand[ran] = current;
        j++;
      }
    }
  }

  int grillerand[5][8]; /*initialisation du tableau contenant les cartes aléatoires*/
  int ligne, colonne;
  i = 0;

  for ( ligne = 0; ligne < cartex; ligne++ )
  {
    for (colonne = 0; colonne < cartey; colonne++)
    {
      grillerand[ligne][colonne] = spritesRand[i]; /*On attribue les sprite aux différentes cases du tableau*/
      AfficherSprite(backcard, x, y); /*On affiche les dos de cartes dans toutes les cases du tableau*/
      x = x + marge + longueurImage;
      i++;
    }
    x = marge;
    y = y + marge + largeurImage;
  }

  int selection = 0, score = 0, selectionx = 0, selectiony = 0;
  int tempo = 0;
  ChoisirEcran(2); /*On utilise un second écran virtuel avec un fond dans lequel on fera tourner le compteur*/
  ChargerImageFond("../Image/fond.png");
  ChoisirEcran(0);

  int spritetrouve[20], k, dejatrouve = 0; /*tableau destiné a contenir les sprites dejà trouvé*/
  
  for (k = 0; k < 20; k++)
  {
    spritetrouve[k] = 0;
  }

  while (goon == 1)
  {
    if (ToucheEnAttente() && Touche() == XK_t && tempo == 0) /*initialisation du mode triche*/
    {
      int ligne, colonne;
      tempo = 1;
      CopierZone(0,3,0,70,(longueurImage*cartey + marge*cartey),(largeurImage*cartex + marge*cartex),0,70); /*copie de l'écran actuelle dans un écran tampon*/
      ChoisirEcran(2);
      x = marge;
      y = 70;

      for ( ligne = 0; ligne < cartex; ligne++ ) /*boucle qui affiche les cartes côté sprite dans la grille*/
      {
        for (colonne = 0; colonne < cartey; colonne++)
        {
          AfficherSprite(grillerand[ligne][colonne], x, y);
          x = x + marge + longueurImage;
        }
        x = marge;
        y = y + marge + largeurImage;
      }
      CopierZone(2,0,0,70,(longueurImage*cartey + marge*cartey),(largeurImage*cartex + marge*cartex),0,70);

      while (tempo == 1)
      {
        if (ToucheEnAttente() && Touche() == XK_t) /*Condition de sortie du mode triche*/
        {
          tempo = 0;
        }
      }
      CopierZone(3,0,0,70,(longueurImage*cartey + marge*cartey),(largeurImage*cartex + marge*cartex),0,70);/*On reprend l'écran précedemment sauvegardé dans l'écran tampon*/
    }

    if (Microsecondes()>temps) /*timer*/
    {
      seconde++;
      ChoisirEcran(1);
      EffacerEcran(CouleurParNom("White"));
      ChargerImageFond("../Image/fond.png");
      snprintf(buf,100,"temps : %5d",seconde);
      EcrireTexte(70,30,buf,1);
      CopierZone(1,0,0,0,500,70,0,0);
      ChoisirEcran(0);
      temps = Microsecondes() + CYCLE;
    }

    int i =0;
    x = marge;
    y = 70;

    if(SourisCliquee()) /*condition qui gère le clique de la souris pour retourner les cartes*/
    {
      for(ligne = 0; ligne < cartex; ligne++)
      {
        for(colonne = 0; colonne < cartey; colonne++)
        {
          if ((_X >= x) && (_X <= x + longueurImage) && (_Y >= y) && (_Y <= y + largeurImage))
          {
            for(k = 0; k < 20; k++)
            {
              if (spritetrouve[k] == spritesRand[i]) /*vérification si la paire de carte est identique*/
              {
                dejatrouve = 1;
              }
            }

            AfficherSprite(spritesRand[i],x, y);
            sleep(1); /*mise en veille du programme de 1sec pour la seconde selection, permet de le voir*/
            if(selection == 0 && dejatrouve == 0)
            { /*stocke la valeur du clique dans selection, ses coordonnées dans selectionx et selectiony*/
              selection = spritesRand[i];
              selectionx = x;
              selectiony = y;
            }
            else
            {
              if(selection == spritesRand[i] && (selectionx != x || selectiony != y) )
              { /*si le second clique rempli ses conditions alors on a trouvé une paire*/
                score++;  /*le score s'incrémente jusqu'a avoir trouvé les 10paires (ici) donc si score == 10, goon = 0 (voir plus bas) */
                for ( k = 0; k < 20; k++)
                {
                  if (spritetrouve[k] == 0)
                  {
                    spritetrouve[k] = selection; /*si la carte a déjà été trouvée on ne réaffiche pas le dos par dessus*/
                    break;
                  }
                }
              }
              else
              {
                if (dejatrouve == 0)
                {
                  AfficherSprite(backcard, x, y);  /*si faux, réaffiche le bac par dessus la premi!re selection et la deuxeieme*/
                }
                AfficherSprite(backcard, selectionx, selectiony);
              }
              selection = 0; /*rénitialise les valeurs */
              dejatrouve = 0;
            }
          }
          x = x + marge + longueurImage;
          i++;
        }
        x = marge;
        y = y + marge + largeurImage;
      }
    } 
    if(score == spritesize)
    { /* condition de victoire, return 0 pour montrer la fin*/
      goon = 0;  
    }
    if (ToucheEnAttente() && Touche() == XK_q) /*on peut appuyer sur q pour quitter*/
    {
      goon = 0;
    }
  }
}