#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

#define hfenetre 1280
#define lfenetre 720
#define longueurImage 95
#define largeurImage 95
#define marge 40
#define CYCLE 1000000L

int x = 30;
int y = 55;

int SPRITE_RAND_SIZE = cartex * cartey,
SPRITE_SIZE = SPRITE_RAND_SIZE/2,
MAX = SPRITE_RAND_SIZE,
MIN = 0,
x = marge,
y = 70,
int i; 
int j; 

void menu();
void facile();
void normal();
void difficile();
void regle();
void grille1(int cartex, int cartey);
void grille2();
void grille3();

int goon = 0;

void regle(void){
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

void facile(void)
{
	goon = 1; /*grille facile*/
	FermerGraphique();
	InitialiserGraphique();
	CreerFenetre(10,25,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55));
	ChargerImageFond("../Image/fond.png");
	grille1(4,5);
	while(goon == 1)
	{
		while (!SourisCliquee())
		{
			DessinerRectangle(700,563,100,63);
			SourisCliquee();
			if ( (_X >= 700) && (_X <= 800) && (_Y >= 563) && (_Y <= 616) )
			{
				goon = 0;
				menu();
			}
		}
	}
}

void normal(void)
{
	goon = 2; /*grille normal*/
	ChargerImageFond("../Image/fond.png");
	/*grille2();*/
	while(goon == 2)
	{
		while (!SourisCliquee())
		{
			DessinerRectangle(700,563,100,63);
			SourisCliquee();
			if ( (_X >= 700) && (_X <= 800) && (_Y >= 563) && (_Y <= 616) )
			{
				goon = 0;
				menu();
			}
		}
	}
}

void difficile(void){
	goon = 3;/*grille difficile*/
	ChargerImageFond("../Image/fond.png");
	/*grille3();*/
	while(goon == 3)
	{
		while (!SourisCliquee())
		{
			DessinerRectangle(700,563,100,63);
			SourisCliquee();
			if ( (_X >= 700) && (_X <= 800) && (_Y >= 563) && (_Y <= 616) )
			{
				goon = 0;
				menu();
			}
		}
	}
}

void menu(void)
{

	
	ChargerImageFond("../Image/projet.png"); 

	DessinerRectangle(770,350,63,63);
	DessinerRectangle(620,445,63,63);
	DessinerRectangle(810,555,63,63);
	/* ces trois rectangles initialises les boutons de difficultés*/
	DessinerRectangle(159,294,245,242);
	/* ce rectangle initialise le bouton avec les regles du jeu*/
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
			facile();
		}
		else if ( _X >= 620 && _X <= 683 && _Y >= 445 && _Y <= 508 )
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
		/*else if*/
	}
}

void grille1(int cartex, int cartey)
{
srand(time(NULL));

int sprite[12] = {  /*créer le tableau contenant les sprites*/
ChargerSprite("../../Image/carte1.png"),
ChargerSprite("../../Image/carte2.png"),
ChargerSprite("../../Image/carte3.png"),
ChargerSprite("../../Image/carte4.png"),
ChargerSprite("../../Image/carte5.png"),
ChargerSprite("../../Image/carte6.png"),
ChargerSprite("../../Image/carte7.png"),
ChargerSprite("../../Image/carte8.png"),
ChargerSprite("../../Image/carte9.png"),
ChargerSprite("../../Image/carte10.png"),

};

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

int grillerand[cartex][cartey];

int ligne, colonne;
i = 0;

for ( ligne = 0; ligne < cartex; ligne++ ){

  for (colonne = 0; colonne < cartey; colonne++){

    grillerand[ligne][colonne] = spritesRand[i];

    AfficherSprite(spritesRand[i],x, y);

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

/*void grille2()
{
	srand(time(NULL));

int SPRITE_RAND_SIZE = cartex * cartey,
SPRITE_SIZE = SPRITE_RAND_SIZE/2,
MAX = SPRITE_RAND_SIZE,
MIN = 0,
x = marge,
y = 70,
int i; 
int j; 

int sprite[12] = {  /*créer le tableau contenant les sprites
ChargerSprite("../../Image/carte1.png"),
ChargerSprite("../../Image/carte2.png"),
ChargerSprite("../../Image/carte3.png"),
ChargerSprite("../../Image/carte4.png"),
ChargerSprite("../../Image/carte5.png"),
ChargerSprite("../../Image/carte6.png"),
ChargerSprite("../../Image/carte7.png"),
ChargerSprite("../../Image/carte8.png"),
ChargerSprite("../../Image/carte9.png"),
ChargerSprite("../../Image/carte10.png"),

};

int spritesRand[SPRITE_RAND_SIZE]; /*tableau destiné a accueillir les valeurs random de sprite*/
  
 /* for (i = 0; i < SPRITE_RAND_SIZE; i ++) {     /*incremente le tableau random de 0*/
    
 /*   spritesRand[i] = 0;
  }

  for (i = 0; i < SPRITE_SIZE; i++) {  /*boucle dans le tab des sprites pour garder le sprite courant*/
  /*  int current = sprite[i];

    for (j = 0; j < 2; ) {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
      
   /*   int ran = (rand() % (MAX - MIN) + MIN);

      if (spritesRand[ran] == 0) {  
         
         spritesRand[ran] = current;

         j++;
      }
    }
  }*/

/*int grillerand[cartex][cartey];

int ligne, colonne;
i = 0;

for ( ligne = 0; ligne < cartex; ligne++ ){

  for (colonne = 0; colonne < cartey; colonne++){

    grillerand[ligne][colonne] = spritesRand[i];

    AfficherSprite(spritesRand[i],x, y);

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
}*/

/*void grille3()
{
	srand(time(NULL));

int SPRITE_RAND_SIZE = cartex * cartey,
SPRITE_SIZE = SPRITE_RAND_SIZE/2,
MAX = SPRITE_RAND_SIZE,
MIN = 0,
x = marge,
y = 70,
int i; 
int j; 

int sprite[12] = {  
ChargerSprite("../../Image/carte1.png"),
ChargerSprite("../../Image/carte2.png"),
ChargerSprite("../../Image/carte3.png"),
ChargerSprite("../../Image/carte4.png"),
ChargerSprite("../../Image/carte5.png"),
ChargerSprite("../../Image/carte6.png"),
ChargerSprite("../../Image/carte7.png"),
ChargerSprite("../../Image/carte8.png"),
ChargerSprite("../../Image/carte9.png"),
ChargerSprite("../../Image/carte10.png"),

};

int spritesRand[SPRITE_RAND_SIZE]; /*tableau destiné a accueillir les valeurs random de sprite
  
  for (i = 0; i < SPRITE_RAND_SIZE; i ++) {     
    
    spritesRand[i] = 0;
  }

  for (i = 0; i < SPRITE_SIZE; i++) {  /*boucle dans le tab des sprites pour garder le sprite courant
    int current = sprite[i];

    for (j = 0; j < 2; ) {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
      
    /*  int ran = (rand() % (MAX - MIN) + MIN);

      if (spritesRand[ran] == 0) {  
         
         spritesRand[ran] = current;

         j++;
      }
    }
  }
*/
/*int grillerand[cartex][cartey];

int ligne, colonne;
i = 0;

for ( ligne = 0; ligne < cartex; ligne++ ){

  for (colonne = 0; colonne < cartey; colonne++){

    grillerand[ligne][colonne] = spritesRand[i];

    AfficherSprite(spritesRand[i],x, y);

    x = x + marge + longueurImage;
    
    i++;


  }
  x = marge;

  y = y + marge + largeurImage;

}

 
/*while(goon == 1){
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

}*/



int main(void)
{ 

	InitialiserGraphique();   /*créer la fenetre */
	CreerFenetre(100,25,hfenetre,lfenetre);

	menu();
	

Touche();
FermerGraphique();

return EXIT_SUCCESS;
}
