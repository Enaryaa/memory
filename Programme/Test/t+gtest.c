#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L
#define cartex 4
#define cartey 4

void timer(void)
    {
        
        char buf[100];
        int seconde = 0;
 
         ChoisirEcran(1);
         CopierZone(2,1,0,0,800,500,0,0);
         snprintf(buf,100,"temps : %5d",seconde);
         EcrireTexte(((longueurImage*8 + 30*8 + 20)/2),30,buf,1);
}

int main(void){
	int marge = 30; 
	int x = marge;
	int y = 70; 
	int i, j;
	int goon = 1;
	int seconde = 0;
    unsigned long Microsecondes(), temps;
    temps = (Microsecondes()+CYCLE);

InitialiserGraphique();
CreerFenetre(10,25,800,500);
ChoisirEcran(2);
ChargerImageFond("../../Image/fond.png");

while(goon){

for( i = 0; i < cartex; i++  ){
		for (j = 0; j < cartey; j++){
			int sprite = ChargerSprite("../../Image/carte1.png");
			AfficherSprite(sprite, x, y);
			x = x + marge + longueurImage;
		}
		x = marge;
		y = y + marge + largeurImage;

	if (Microsecondes() >temps){
		seconde++;
		timer();
		temps = (Microsecondes() + CYCLE);
	}
	}
}


Touche();
FermerGraphique();

	return EXIT_SUCCESS;
}