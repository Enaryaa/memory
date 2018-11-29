/*  29/11/2018 */

#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

int main(int argc, char * argv[]){ 
int booleen = 0;

InitialiserGraphique();   /*créer la fenetre */
CreerFenetre(250,120,1280,720);
EffacerEcran(CouleurParNom("blue")); 


DessinerRectangle(515,275,300,120);
/*DessinerRectangle(550,400,300,120); /* met en place les boutons avec des rectangles et y ajoute une image*/
/*ChargerImage("./Image/bouton.png", 550,400,0,0,300,120);*/

DessinerRectangle(515,395,300,120);

	SourisPosition();
	
while (booleen == 0){
	
	SourisCliquee();
		if ( (_X >= 515) && (_X <= 815) && (_Y >= 300) && (_Y <= 420) )
		{
			FermerGraphique();
			InitialiserGraphique();
			CreerFenetre(250, 120, 1280, 720);
			booleen = 1;
		}
		else if ( _X >= 515 && _X <= 815 && _Y >= 395 && _Y <= 515 )
		{
			FermerGraphique();
			InitialiserGraphique();
			CreerFenetre(250, 120, 1280, 720);
			booleen = 1;
		}
	}


/*int grille[8][6];
unsigned int valeur, ligne, colonne;

   for (ligne = 0; ligne < 2; ligne++)
     {
       for (valeur = 1, colonne = 0; colonne < 5; colonne++)
       {
          grille[ligne][colonne] = valeur++;
        }
      }
      for (ligne = 0; ligne < 6; ligne++)
      {
        for (colonne = 0; colonne < 8; colonne++)
        {
          printf("%3d", grille[ligne][colonne]);
        }
        printf("\n");
      }
      printf("\n");*/


Touche();
FermerGraphique();

return EXIT_SUCCESS;
}

