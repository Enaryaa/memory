#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>

#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L

void grille(void);

int main(void)
{    
    int seconde = 0; 
    char buf[100];
           /*initialise seconde à 0 pour commencer le temps à partir de 0*/
    unsigned long temps;

    int goon = 1;

    temps = Microsecondes() + CYCLE;
	
    InitialiserGraphique();
    CreerFenetre(10,25,1200,700);
            ChargerImageFond("../Image/fond.png");

    ChoisirEcran(1);



    while (goon == 1)
    {
        /*grille();*/
  
        if (Microsecondes()>temps)
        {
        	seconde++;
            CopierZone(1,0,0,0,500,70,0,0);
            ChoisirEcran(1);
            snprintf(buf,100,"temps : %5d",seconde);
            EcrireTexte(70,30,buf,1);
            
            printf("%d\n", seconde);
            temps = Microsecondes() + CYCLE;
        }
    	
        Touche();
    	FermerGraphique();
    	return EXIT_SUCCESS;
    }
}

void grille(void)
{
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

    int sprite[12] = {
    ChargerSprite("../Image/carte1.png"),
    ChargerSprite("../Image/carte2.png"),
    ChargerSprite("../Image/carte3.png"),
    ChargerSprite("../Image/carte4.png"),
    ChargerSprite("../Image/carte5.png"),
    ChargerSprite("../Image/carte6.png"),
    ChargerSprite("../Image/carte7.png"),
    ChargerSprite("../Image/carte8.png"),
    ChargerSprite("../Image/carte9.png"),
    ChargerSprite("../Image/carte10.png")};


    int spritesRand[SPRITE_RAND_SIZE];

    for (i = 0; i < SPRITE_RAND_SIZE; i ++)
    {  /*incremente le tableau random de 0*/
    	spritesRand[i] = 0;
    }

    for (i = 0; i < SPRITE_SIZE; i++)
    {  /*boucle dans le tab des sprites pour garder le sprite courant*/
        /*printf("%d\n", i);*/
        int current = sprite[i];
        /*printf("%s\n", current);*/
        for (j = 0; j < TWO_CARD;)
        {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
        	int randKey = (rand() % (MAX - MIN) + MIN);
          	/*printf("%d\n", randKey);
          	printf("%s\n", spritesRand[randKey]);*/
          	if (spritesRand[randKey] == 0)
          	{  /*le curseur cherche aléatoirement un espace dans le tab*/
            	spritesRand[randKey] = current;
            	/*rintf("%s\n", spritesRand[randKey]);*/
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

        	AfficherSprite(spritesRand[i],x, y);

        	x = x + marge + longueurImage;
        
        	i++;

      	}
      	x = marge;

      	y = y + marge + largeurImage;

    }
}