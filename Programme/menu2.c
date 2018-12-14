#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include<math.h>

#define CYCLE 1000000L
#define longueurImage 95
#define largeurImage 95
#define marge 40

int i, j, ligne, colonne, x, y = 70, goon = 1; 
int SPRITE_RAND_SIZE,
SPRITE_SIZE,
MAX,
MIN = 0;

void Menu();
void Regle();
int Facile();

int main (void){
	int seconde = 0;
	char time[100];
	unsigned long temps = Microseconde() + CYCLE;

	InitialiseGraphique();
	CreerFenetre(100,25,1280,720);
	ChoisirEcran(1);
	ChargerImageFond("../Image/projet.png");
	Menu();

		while (goon == 1){
			if (Microseconde()> temps){
				CopierZone(1,0,0,0,1200,70,0,0);
				ChoisirEcran(0);
				snprintf(time,100,"Temps : %5d", seconde);
				EcrireTexte(70,70,time,1);
				seconde++;
				temps = Microseconde() + CYCLE;
			}
		}
		Touche();
		FermerGraphique();

		return EXIT_SUCCESS;
}

void Menu()
{

	SourisPosition();
		/*permet de connaitre la position actuelle du curseur */

	while (goon == 0)
	{
	
		SourisCliquee();
		if ( (_X >= 770) && (_X <= 833) && (_Y >= 350) && (_Y <= 413) ) 
		/*si l'utilisateur clique dans cette surface 
		(qui correspond a un bouton) alors on ferme la fenetre actuelle pour en ouvrir 
		une autre contenant les différentes grilles de jeu*/
		{
			Facile(4,5);
		}
		/*else if ( _X >= 620 && _X <= 683 && _Y >= 445 && _Y <= 508 )
		{
			normal();
		}
		else if ( _X >= 810 && _X <= 873 && _Y >= 555 && _Y <= 618 )
		{
			difficile();
		}
		else if ( _X >= 159 && _X <= 404 && _Y >= 294 && _Y <= 586 )
		{
			regle();
			SourisCliquee();
		}
	}*/
}

void Regle(void){
	goon = 4;
	while(goon == 4)
	{
		while (!SourisCliquee())
		{
			ChargerImageFond("../Image/regle22.png");
			/*image de fond a redimensionner pour un truc propre*/
			DessinerRectangle(700,563,100,63);
			SourisCliquee();
			if ( (_X >= 700) && (_X <= 800) && (_Y >= 563) && (_Y <= 616) )
				/*bouton a ajouter en sprite*/
			{
				goon = 0;
				menu();
			}
		}
	}
}

int Facile(int cartex, int cartey)
{
	goon = 1; /*grille facile*/
	FermerGraphique();
	InitialiserGraphique();
  	CreerFenetre(100,25,(longueurImage*5 + marge*5 + 20),(largeurImage*5 + marge*5 +55));
  	/*j'ai défini ici la taille de la fenetre lorsqu'on lance facile, cela permet d'avoir une page 
  	propre sans avoir besoin de changer la taille des sprites, je trouve ca plus simple*/
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
	ChargerSprite("../Image/carte10.png")
	};
	int sprite2 = ChargerSprite("../Image/back.png");

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
int grillerand[4][5];

int ligne, colonne;
i = 0;

for ( ligne = 0; ligne < 4; ligne++ ){

  for (colonne = 0; colonne < 5; colonne++){

    grillerand[ligne][colonne] = spritesRand[i];

    AfficherSprite(sprite2, x, y);

    x = x + marge + longueurImage;

    i++;
  }

  x = marge;

  y = y + marge + largeurImage;

}


while(goon == 1){

int i =0;
x = marge;
y = 70;

  if(SourisCliquee()){

    for(ligne = 0; ligne < 4; ligne++ )
    {
    
      for(colonne = 0; colonne < 5; colonne++)
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
}
}
}