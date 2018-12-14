    #include <stdio.h>
    #include <stdlib.h>
    #include <graph.h>
    /*#include <timer.h>*/

    #define TX 1200
    #define TY 800
    #define DELTA 1000000L
    int evenement = 0;

    /*Prototype des fonctions*/
    void Menu(void); /*Affiche le Menu Principal*/
    int Selection(void); /*Permet de gérer la selection des boutons de difficultés*/
    int Grid(int nbcartesX,int nbcartesY,int difficulte); /*Affiche une grille de jeu de nbcartesX * nbcartesY*/
    void Updatecard(void); /*Retourne une carte de sa face caché à sa face decouverte */
    void Return(void); /*Permet de retourner au Menu Principal*/
    void Cheatmode(void); /*Active le cheatmode*/

    int main (void)
    {
      int seconde = 0;
      char time[100];
      unsigned long suivant = Microsecondes() + DELTA;

      /*Ouvre un graphique puis une fenetre avec son positionnement et ses dimensions en parametres*/
      InitialiserGraphique();
      CreerFenetre(350,350,TX,TY);
      ChoisirEcran(1);
      ChargerImageFond("./IMAGE/FOND.png");
      ChoisirCouleurDessin(CouleurParNom("orange"));

      Menu();
    	Selection();

        while (evenement == 0)
        {
        	Cheatmode();
          if (Microsecondes() > suivant)
          {
            CopierZone(1,0,0,0,1200,70,0,0);
            ChoisirEcran(0);
            snprintf(time,100,"TIME : %5d",seconde);
            EcrireTexte(70,70,time,1);
            seconde++;
            suivant = Microsecondes() + DELTA;
          }
        }

        Touche();
        FermerGraphique();

        return EXIT_SUCCESS;
    }

    void Menu(void)
    {
      ChoisirEcran(0);
      ChargerImageFond("./IMAGE/MENU.png");
    }

    int Selection(void)
    {
      /*Boutons JOUER et INFO*/
      while (evenement == 0)
      {
        if (SourisCliquee())
        {
          if ((_X >= 535) && (_X <= 685) && (_Y >= 345) && (_Y <= 425))
          {
            evenement = 1;
          }
          else if ((_X >= 535) && (_X <= 685) && (_Y >= 490) && (_Y <= 570))
          {
            evenement = 2;
          }
        }
      }
      /*Affichage et gestion de la selection de la difficulte si on a appuyer sur JOUER*/
      if (evenement == 1)
      {
      	evenement = 0;
        ChargerImageFond("./IMAGE/JOUER.png");
        while (evenement == 0)
        {
          if (SourisCliquee())
          {
            if ((_X >= 460) && (_X <= 725) && (_Y >= 310) && (_Y <= 345))
            {
              evenement = 1;
            }
            else if ((_X >= 460) && (_X <= 725) && (_Y >= 385) && (_Y <= 415))
            {
              evenement = 2;
            }
            else if ((_X >= 410) && (_X <= 780) && (_Y >= 460) && (_Y <= 490))
            {
              evenement = 3;
            }
          }
        }
    	    if (evenement == 1)
    		{
              evenement = 0;
              Grid(5,4,1); /*Affiche une grille 5x4 correspondant à difficulte 1*/
      		}

    		else if (evenement == 2)
    		{
              evenement = 0;
              Grid(6,5,2); /*Affiche une grille 6x5 correspondant à difficulte 2*/
    		}

    	    else if (evenement == 3)
    	    {
              evenement = 0;
              Grid(7,6,3); /*Affiche une grille 7x6 correspondant à difficulte 3*/
    		}
      }
      /*Affichage des informations du jeu si on appuie sur INFO*/
      else if (evenement == 2)
      {
        evenement = 0;
        ChargerImageFond("./IMAGE/INFO.png");
        Return();
      }
    }

    int Grid(int nbcartesX,int nbcartesY,int difficulte)
    {
      int x,y;
      int ligne,colonne;
      /*Melanger et affiche la grille en fonction du nombre de paire correspondant à la difficulte*/
      /*Facile 5x4*/
      if(difficulte == 1)
      {
        srand(time(NULL));
        char sprite[10] = {
        ChargerSprite("./IMAGE/Image1.png"),
        ChargerSprite("./IMAGE/Image2.png"),
        ChargerSprite("./IMAGE/Image3.png"),
        ChargerSprite("./IMAGE/Image4.png"),
        ChargerSprite("./IMAGE/Image5.png"),
        ChargerSprite("./IMAGE/Image6.png"),
        ChargerSprite("./IMAGE/Image7.png"),
        ChargerSprite("./IMAGE/Image8.png"),
        ChargerSprite("./IMAGE/Image9.png"),
        ChargerSprite("./IMAGE/Image10.png"),
        };
        int i, j;
        int grillerand[5][4];
        int nbsprite = 10, nbpaire = nbcartesX * nbcartesY, MAX = nbpaire, MIN = 0;
        int spriterand[MAX];

        ChargerImageFond("./IMAGE/FOND.png");
        
        for(i = 0; i < nbpaire; i++)
        {
            spriterand[i] = 0;
        }

        for (colonne = 0; colonne < nbsprite; colonne++)
        {
          int current = sprite[i];
          for(ligne = 0; ligne < 2;)
          {
            int randkey = (rand() % (MAX - MIN) + MIN);
            if(spriterand[randkey] == 0 )
            {
              spriterand[randkey] = current;
              ligne++;
              i++;
            }
          }
        }

        for (colonne = 0, y = 300; colonne < nbcartesY; colonne++)
        {
          for (ligne = 0, x = 400; ligne < nbcartesX; ligne++)
          {
            DessinerRectangle(x,y,50,50);
            grillerand[nbcartesX][nbcartesY] = spriterand[i];
            AfficherSprite(spriterand[i],x,y);
            x = x + 90;
            i++;
          }
          y = y + 90;
        }
      }
      /*Normal 6x5*/
      if(difficulte == 2)
      {
        srand(time(NULL));
        char sprite[4] =
        {
        ChargerSprite("./IMAGE/Image1.png"),
        ChargerSprite("./IMAGE/Image2.png"),
        ChargerSprite("./IMAGE/Image3.png"),
        ChargerSprite("./IMAGE/Image4.png")
        };
        int i, j;
        int grillerand[5][4];
        int nbsprite = 4, nbpaire = 8, max = 20, min = 0;
        int spriterand[nbpaire];

        ChargerImageFond("./IMAGE/FOND2.png");
        for(i = 0; i < nbpaire; i++)
        {
            spriterand[i] = 0;
        }
        for (colonne = 0; colonne < nbsprite; colonne++)
        {
          int current = sprite[i];
          for(ligne = 0; ligne < 2;)
          {
            int randkey = (rand() % (max - min) + min);
            if(spriterand[randkey] == 0 )
            {
              spriterand[randkey] = current;
              ligne++;
              i++;
            }
          }
        }

        for (colonne = 0, y = 300; colonne < nbcartesY; colonne++)
        {
          for (ligne = 0, x = 400; ligne < nbcartesX; ligne++)
          {
            DessinerRectangle(x,y,50,50);
            grillerand[nbcartesX][nbcartesY] = spriterand[i];
            AfficherSprite(spriterand[i],x,y);
            x = x + 90;
            i++;
          }
          y = y + 90;
        }
      }
      /*Difficile 7x6*/
      if(difficulte == 3)
      {
        srand(time(NULL));
        char sprite[4] =
        {
        ChargerSprite("./IMAGE/Image1.png"),
        ChargerSprite("./IMAGE/Image2.png"),
        ChargerSprite("./IMAGE/Image3.png"),
        ChargerSprite("./IMAGE/Image4.png")
        };
        int i, j;
        int grillerand[5][4];
        int nbsprite = 4, nbpaire = 8, max = 20, min = 0;
        int spriterand[nbpaire];

        ChargerImageFond("./IMAGE/FOND3.png");
        for(i = 0; i < nbpaire; i++)
        {
            spriterand[i] = 0;
        }
        for (colonne = 0; colonne < nbsprite; colonne++)
        {
          int current = sprite[i];
          for(ligne = 0; ligne < 2;)
          {
            int randkey = (rand() % (max - min) + min);
            if(spriterand[randkey] == 0 )
            {
              spriterand[randkey] = current;
              ligne++;
              i++;
            }
          }
        }

        for (colonne = 0, y = 300; colonne < nbcartesY; colonne++)
        {
          for (ligne = 0, x = 400; ligne < nbcartesX; ligne++)
          {
            DessinerRectangle(x,y,50,50);
            grillerand[nbcartesX][nbcartesY] = spriterand[i];
            AfficherSprite(spriterand[i],x,y);
            x = x + 90;
            i++;
          }
          y = y + 90;
        }
      }

    }

    void Updatecard(void)
    {
        int nbcartesX, nbcartesY;
        int x,y;
        int ligne, colonne;

        if (SourisCliquee())
        {
            for (colonne = 0, y = 300; colonne < nbcartesY; colonne++)
            {
                for (ligne = 0, x = 400; ligne < nbcartesX; ligne++)
                {
                    if ((_X >= x) && (_X <= x + 50) && (_Y >= y ) && (_Y <= y + 50))
                    {
                        RemplirRectangle(x,y,50,50);
                    }
                    x = x + 90;
                }
                y = y + 90;
            }

        }
    }

    void Return(void)
    {
        if (Touche() == XK_Escape)
        {
            FermerGraphique();
            main();
        }
    }

    void Cheatmode(void)
    {
      if (Touche() == XK_t)
      {
        EcrireTexte(300,70,"CHEATMODE ACTIVATED",2);
      }
    }
