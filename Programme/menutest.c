#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

void menu();
void facile();
void normal();
void difficile();
void regle();

int goon = 0;

void regle(void){
	goon = 1;
	InitialiserGraphique();
	CreerFenetre(200, 300, 900, 700);
	while (!SourisCliquee())
	{
		ChargerImageFond("../Image/regle22.png");
		DessinerRectangle(700,563,100,63);
		SourisCliquee();
		if ( (_X >= 700) && (_X <= 800) && (_Y >= 563) && (_Y <= 616) )
		{
			FermerGraphique();
			goon = 0;
			menu();
		}
	}
}

void facile(int cartex, int cartey){
	FermerGraphique();
	InitialiserGraphique(); /*  grille facile*/
	CreerFenetre(200, 300, 1280, 720);
	ChargerImageFond("../Image/fond.png");
	goon = 1;
}

void normal(int cartex, int cartey){
	FermerGraphique();
	InitialiserGraphique(); /*grille normal */
	CreerFenetre(200, 300, 1280, 720);
	ChargerImageFond("../Image/fond.png");
	goon = 2;
}

void difficile(int cartex, int cartey){
	FermerGraphique();
	InitialiserGraphique();
	CreerFenetre(200, 300, 1280, 720); /*grille difficile*/
	ChargerImageFond("../Image/fond.png");
	goon = 3;
}

void menu()
{

	InitialiserGraphique();   /*créer la fenetre */
	CreerFenetre(200,190,1280,720);
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
		if ( (_X >= 770) && (_X <= 833) && (_Y >= 350) && (_Y <= 413) ) /*si l'utilisateur clique dans cette surface 
		(qui correspond a un bouton) alors on ferme la fenetre actuelle pour en ouvrir une autre contenant les différentes grilles de jeu*/
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
			FermerGraphique();
			regle();
			SourisCliquee();
			if (&SourisCliquee)
			{
				FermerGraphique();
				menu();
				goon = 0;
			}
		}
	}
}



int main(void){ 

	menu();
	

Touche();
FermerGraphique();

return EXIT_SUCCESS;
}
