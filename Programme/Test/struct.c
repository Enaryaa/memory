#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>
#include<time.h>
#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L
/*#define cartex 4
#define cartey 4*/


int main (void){

int marge = 30; 
int x = marge;
int y = 70; 
int i, j;


InitialiserGraphique();
CreerFenetre(10,25,1200,700); 

int sprite[5] = {
ChargerSprite("../../Image/carte1.png"),
ChargerSprite("../../Image/carte2.png"),
ChargerSprite("../../Image/carte3.png"),
ChargerSprite("../../Image/carte4.png"),
ChargerSprite("../../Image/carte5.png")

};


	for( i = 0; i < 6; i++  ){
		for (j = 0; j < 5; j++){
			AfficherSprite(sprite[i], x, y);
			x = x + marge + longueurImage;
		}
		x = marge;
		y = y + marge + largeurImage;

	}


Touche();
FermerGraphique();

    return EXIT_SUCCESS;
}
