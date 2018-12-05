#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define delta 1000000L
 
void DessinerScene(int sprite,int x,int y,int n)
{
	char buf[100];
	ChoisirEcran(1);
	CopierZone(2,1,0,0,800,500,0,0);
	snprintf(buf,100,"temps : %05d",n);
	EcrireTexte(10,20,buf,0);
	AfficherSprite(sprite,x,y);
	CopierZone(1,0,0,0,800,500,0,0);
}
 
int main()
{
	int pingouin;
	int x,y,old_x,old_y;
	int n;
	unsigned long suivant;
	int go_on=1;
 
	InitialiserGraphique();
	CreerFenetre(0,0,800,500);
	ChoisirEcran(2);
	/*ChargerImageFond("");		 
	pingouin=ChargerSprite("./images/walk-0.png");*/
	x=y=old_x=old_y=10;
	n=0;
	DessinerScene(pingouin,x,y,0);
	suivant=Microsecondes()+delta;
 
	while(go_on)
	{
		if (SourisCliquee()) go_on=0;
		else
		{
			if (Microsecondes()>suivant)
			{
				n++;
				DessinerScene(pingouin,x,y,n);
				suivant=Microsecondes()+delta;
			}
			SourisPosition();
			x=_X;
			y=_Y;
			if (x!=old_x || y!=old_y)
			{
				DessinerScene(pingouin,x,y,n);
				old_x=x;
				old_y=y;
			}
		}
	}
	FermerGraphique();
}
 