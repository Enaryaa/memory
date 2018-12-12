#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>


int sprite(){

int sprite1 = ChargerSprite("../../Image/carte1.png");
int sprite2 = ChargerSprite("../../Image/carte2.png");
int sprite3 =ChargerSprite("../../Image/carte3.png");
int sprite4 =ChargerSprite("../../Image/carte4.png");
int sprite5 =ChargerSprite("../../Image/carte5.png");
int sprite6 =ChargerSprite("../../Image/carte6.png");
int sprite7 =ChargerSprite("../../Image/carte7.png");
int sprite8 =ChargerSprite("../../Image/carte8.png");
int sprite9 =ChargerSprite("../../Image/carte9.png");
int sprite10 =ChargerSprite("../../Image/carte10.png");
int sprite11=ChargerSprite("../../Image/carte11.png");
int sprite12 =ChargerSprite("../../Image/carte12.png");
int sprite13 =ChargerSprite("../../Image/carte13.png");
int sprite14 =ChargerSprite("../../Image/carte14.png");

return EXIT_SUCCESS;
}

int main(){
InitialiserGraphique();
CreerFenetre(10,25,1000,500);
int x;
int y;
goon = 1;
sprite();
while(goon=1){

AffichierSprite(sprite1,x ,y);

}
return EXIT_SUCCESS;
}