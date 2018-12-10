#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L
#define cartex 4
#define cartey 4

int main(void){
	int marge = 30; 
	int x = marge;
	int y = 70; 
	int i, j;

InitialiserGraphique();
CreerFenetre(10,25,(longueurImage*cartex + marge*cartex + 20),
	(largeurImage*cartey + marge*cartey +70));

	for( i = 0; i < cartex; i++  ){
		for (j = 0; j < cartey; j++){
			int sprite = ChargerSprite("../../Image/carte1.png");
			AfficherSprite(sprite, x, y);
			x = x + marge + longueurImage;
		}
		x = marge;
		y = y + marge + largeurImage;

	}

Touche();
FermerGraphique();

	return EXIT_SUCCESS;
}