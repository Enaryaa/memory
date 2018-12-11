#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>

int main(void){
int marge = 30; 
int x = marge;
int y = 70; 
int i, j;

InitialiserGraphique();
CreerFenetre(10,25,1200,700); 


int sprite = ChargerSprite("../../Image/carte1.png"); 
AfficherSprite(sprite, x,y );
if(SourisCliquee())
{
	LibererSprite(sprite);
}

Touche();
FermerGraphique();

return 0;
}