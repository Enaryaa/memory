/*  30/11/2018 */

#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

int booleen = 0;


void menu(){

InitialiserGraphique();   /*créer la fenetre */
CreerFenetre(200,190,1280,720);
ChargerImageFond("Image/projet.png"); 


DessinerRectangle(770,350,63,63);
DessinerRectangle(620,450,63,63);
DessinerRectangle(810,560,63,63);
/* ces trois rectangles initialises les boutons de difficultés*/
DessinerRectangle(159,294,245,242);
/* ce rectangle initialise le bouton avec les regles du jeu*/
}

void regle(){
	InitialiserGraphique();
	CreerFenetre(200, 300, 900, 700);
	ChargerImageFond("Image/regle22.png");
	booleen = 1;
}



int main(int argc, char * argv[]){ 

	menu();
	SourisPosition();
	/*permet de connaitre la position actuelle du curseur */

while (booleen == 0){
	
	SourisCliquee();
		if ( (_X >= 770) && (_X <= 833) && (_Y >= 350) && (_Y <= 413) ) /*si l'utilisateur clique dans cette surface 
		(qui correspond a un bouton) alors on ferme la fenetre actuelle pour en ouvrir une autre contenant les différentes grilles de jeu*/
		{
			FermerGraphique();
			InitialiserGraphique(); /* ouvre grille facile*/
			CreerFenetre(200, 300, 1280, 720);
			ChargerImageFond("Image/fond.png");
			booleen = 1;
		}
		else if ( _X >= 620 && _X <= 683 && _Y >= 450 && _Y <= 513 )
		{
			FermerGraphique();
			InitialiserGraphique(); /*grille normal */
			CreerFenetre(200, 300, 1280, 720);
			ChargerImageFond("Image/fond.png");
			booleen = 1;
		}
		else if ( _X >= 810 && _X <= 873 && _Y >= 560 && _Y <= 623 )
		{
			FermerGraphique();
			InitialiserGraphique();
			CreerFenetre(200, 300, 1280, 720); /*grille difficile*/
			ChargerImageFond("Image/fond.png");
			booleen = 1;
		}
		else if ( _X >= 159 && _X <= 404 && _Y >= 294 && _Y <= 586 )
		{
			FermerGraphique();
			regle();
			/*while (&regle){
			if (&SourisCliquee){
				FermerGraphique();
				menu();*/
		}
	}



Touche();
FermerGraphique();

return EXIT_SUCCESS;
}

