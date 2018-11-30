/*  30/11/2018 */

#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

struct card
{
	char sprite[20];
	int x;
	int y;
	int isReturned;
};

/*ces valeurs ici ont on été ajouté pour l'exemple , il fautdra placer les 24 sprites*/
char sprite[4][50] = { "coeur", "pique", "carreau", "trefle" };

/* lite aleatoire ICI il faut que ce tableau soit généré aleatoirement avec chaque carte en deux exemplaire*/
char randomize[8][50] = {"coeur", "pique", "coeur", "trefle", "carreau", "trefle", "carreau", "pique"}

int booleen = 0;


void menu(){

InitialiserGraphique();   /*créer la fenetre */
CreerFenetre(200,190,1280,720);
ChargerImageFond("../Image/projet.png"); 


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
	ChargerImageFond("../Image/regle22.png");
	booleen = 1;
}

int main(int argc, char * argv[]){ 
	/* rappel : ne pas oublier de définir la constante des longueurs d'image*/
	/*struct card heart = {"heart.png", 10, 20, 0};*/
	/*ici on applique une marge pour afficher une belle grille avec les images*/
	int marge = 4;
	/*ici on défini la première position x*/
	int x = marge;
	/*de même pour y*/
	int y = marge;

	/* ce tableau doit être rempli grace au tableau randomize pour chaque carte*/
	struct card tableau[8][6];
	/*on défini une cle pour pour recuperer le sprite de la liste aleatoire,
	 il sera incrmenté dans la seoncde boucle for*/
	int random = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			tableau[i][j] = {randomize[random], x, y, 0};
			x = x + marge + longueurImage;
			y = y + marge + largeurImage;
			random = random + 1;
			/*a ce moment là, on peut afficher les images mais face caché*/
		}
	}


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
			ChargerImageFond("../Image/fond.png");
			booleen = 1;
		}
		else if ( _X >= 620 && _X <= 683 && _Y >= 450 && _Y <= 513 )
		{
			FermerGraphique();
			InitialiserGraphique(); /*grille normal */
			CreerFenetre(200, 300, 1280, 720);
			ChargerImageFond("../Image/fond.png");
			booleen = 1;
		}
		else if ( _X >= 810 && _X <= 873 && _Y >= 560 && _Y <= 623 )
		{
			FermerGraphique();
			InitialiserGraphique();
			CreerFenetre(200, 300, 1280, 720); /*grille difficile*/
			ChargerImageFond("../Image/fond.png");
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

