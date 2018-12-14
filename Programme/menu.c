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
	FermerGraphique();
	InitialiserGraphique();
  	CreerFenetre(100,25,(longueurImage*5 + marge*5 + 20),(largeurImage*5 + marge*5 +55));
  	/*j'ai défini ici la taille de la fenetre lorsqu'on lance facile, cela permet d'avoir une page 
  	propre sans avoir besoin de changer la taille des sprites, je trouve ca plus simple*/
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

void menu()
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
	/*ces valeurs ici on été ajouté pour l'exemple , il fautdra placer les 24 sprites*/
	char sprite[4][24] = { "../Image/carte1.png", "../Image/carte2.png", "../Image/carte3.png", "../Image/carte4.png"};

  	/* liste aleatoire ICI il faut que ce tableau soit généré aleatoirement avec chaque carte en deux exemplaire*/
  	char randomize[8][50] = {"../Image/carte1.png", "../Image/carte2.png", "../Image/carte3.png", "../Image/carte4.png" "../Image/carte1.png", "../Image/carte2.png", "../Image/carte3.png", "../Image/carte4.png"};

  	/* rappel : ne pas oublier de définir la constante des longueurs d'image*/
  	/*struct card heart = {"heart.png", 10, 20, 0};*/
  	/*ici on applique une marge pour afficher une belle grille avec les images*/
	/*int marge = 30;*/
 	 /*ici on défini la première position x*/
	


  	/* ce tableau doit être rempli grace au tableau randomize pour chaque carte */
  	struct card tableau[5][5];
  	/*on défini une cle pour pour recuperer le sprite de la liste aleatoire,
  	 il sera incrmenté dans la seoncde boucle for*/
  	/*InitialiserGraphique();
  	CreerFenetre(100,25,(longueurImage*8 + marge*8 + 20),(largeurImage*6 + marge*6 +55));*/
  
  	while(goon == 1)
  	{
    	/*timer();*/
	  	int random = 0;
	    int i, j;

	    for ( i = 0; i < 5; i++)
	    {    
	    	for ( j = 0; j < 5; j++)
      		{
      			struct card current = {"", x, y, 0 };
        		tableau[i][j] = current;
        		/*DessinerRectangle(x, y,longueurImage, largeurImage);*/
        		int sprite = ChargerSprite(randomize[random]);
       			AfficherSprite(sprite, x, y);
       			ChargerImage(randomize[random], x, y, x + longueurImage, y + largeurImage, longueurImage, largeurImage);
        		x = x + marge +longueurImage;
        		random = random + 1;
        		/*a ce moment là, on peut afficher les images mais face caché*/    
      		}
      		x = 30; 
      		y = y + marge + largeurImage;
    	}
	}
}

/*void grille2()
{
	char sprite[4][24] = { "./data/Image/carte1.png", "./data/Image/carte2.png", "./data/Image/carte3.png", "./data/Image/carte4.png"};
	char randomize[8][50] = {"./data/Image/carte1.png", "./data/Image/carte2.png", "./data/Image/carte3.png", "./data/Image/carte4.png" "./data/Image/carte1.png", "./data/Image/carte2.png", "./data/Image/carte3.png", "./data/Image/carte4.png"};
	int marge = 30;
	int x = marge;
	int y = 55;
	struct card tableau[8][6];
	while(goon == 1)
	{
		int random = 0;
    	int i, j;

    	for ( i = 0; i < 6; i++)
    	{    
    	  	for ( j = 0; j < 8; j++)
    	  	{
      			struct card current = {"", x, y, 0 };
      			tableau[i][j] = current;
    		  	DessinerRectangle(x, y,longueurImage, largeurImage);
    		  	int sprite = ChargerSprite(randomize[random]);
    		  	AfficherSprite(sprite, x, y);
    		  	/*ChargerImage(randomize[random], x, y, x + longueurImage, y + largeurImage, longueurImage, largeurImage);*/
     		 	/*x = x + marge +longueurImage;
     		 	random = random + 1;
     		 	x = x + marge +longueurImage;
     		 	random = random + 1;
    	  	}
   	 		x = marge; 
     		y = y + marge + largeurImage;
     	}
    }
}

void grille3()
{
	char sprite[4][24] = { "./data/Image/carte1.png", "./data/Image/carte2.png", "./data/Image/carte3.png", "./data/Image/carte4.png"};
	char randomize[8][50] = {"./data/Image/carte1.png", "./data/Image/carte2.png", "./data/Image/carte3.png", "./data/Image/carte4.png" "./data/Image/carte1.png", "./data/Image/carte2.png", "./data/Image/carte3.png", "./data/Image/carte4.png"};
	int marge = 30;
	int x = marge;
	int y = 55;
	struct card tableau[8][6];
	while(goon == 1)
	{
		int random = 0;
    	int i, j;

    	for ( i = 0; i < 6; i++)
    	{    
    	  	for ( j = 0; j < 8; j++)
    	  	{
      			struct card current = {"", x, y, 0 };
      			tableau[i][j] = current;
    		  	DessinerRectangle(x, y,longueurImage, largeurImage);
    		  	int sprite = ChargerSprite(randomize[random]);
    		  	AfficherSprite(sprite, x, y);
    		  	/*ChargerImage(randomize[random], x, y, x + longueurImage, y + largeurImage, longueurImage, largeurImage);*/
     		 	/*x = x + marge +longueurImage;
     		 	random = random + 1;
     		 	x = x + marge +longueurImage;
     		 	random = random + 1;
    	  	}
   	 		x = marge; 
     		y = y + marge + largeurImage;
     	}
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
