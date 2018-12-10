#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

#define longueurImage 95
#define largeurImage 95
#define marge 30

int x = 30;
int y = 55;
/*j'ai eu des soucis avec x = marge alors j'ai defini x avec la meme valeur que marge*/

void menu();
void facile();
void normal();
void difficile();
void regle();
void grille1();
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

void facile(int cartex, int cartey)
{
	goon = 1; /*grille facile*/
	ChargerImageFond("../Image/fond.png");
	grille1();
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

void normal(int cartex, int cartey)
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

void difficile(int cartex, int cartey){
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
			facile(4, 4);
		}
		else if ( _X >= 620 && _X <= 683 && _Y >= 445 && _Y <= 508 )
		{
			normal(7, 5);
		}
		else if ( _X >= 810 && _X <= 873 && _Y >= 555 && _Y <= 618 )
		{
			difficile(8, 6);
		}
		else if ( _X >= 159 && _X <= 404 && _Y >= 294 && _Y <= 586 )
		{
			regle();
			SourisCliquee();
		}
		/*else if*/
	}
}

void grille1()
{
	int x = marge;
	int y = 55; 
	int i, j;

	for( i = 0; i < 4; i++  ){
		for (j = 0; j < 4; j++){
			int sprite = ChargerSprite("../Image/carte1.png");
			AfficherSprite(sprite, x, y);
			x = x + marge + longueurImage;
		}
		x = marge;
		y = y + marge + largeurImage;

	}
}

/*void grille2()
{
	int x = marge;
	int y = 55; 
	int i, j;

	for( i = 0; i < 6; i++  ){
		for (j = 0; j < 5; j++){
			int sprite = ChargerSprite("../Image/carte1.png");
			AfficherSprite(sprite, x, y);
			x = x + marge + longueurImage;
		}
		x = marge;
		y = y + marge + largeurImage;

	}
}

void grille3()
{
	int x = marge;
	int y = 55; 
	int i, j;

	for( i = 0; i < 8; i++  ){
		for (j = 0; j < 6; j++){
			int sprite = ChargerSprite("../Image/carte1.png");
			AfficherSprite(sprite, x, y);
			x = x + marge + longueurImage;
		}
		x = marge;
		y = y + marge + largeurImage;

	}

}*/



int main(void)
{ 

	InitialiserGraphique();   /*créer la fenetre */
	CreerFenetre(100,25,1280,720);

	menu();
	

Touche();
FermerGraphique();

return EXIT_SUCCESS;
}
