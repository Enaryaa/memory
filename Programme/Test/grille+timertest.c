#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

#define longueurImage 95
#define largeurImage 95
#define CYCLE 1000000L

struct card
{
  int id;
  char sprite[25];
  int x;
  int y;
  int isReturned;
};

void structcard(void){

  struct card a = {0, "../Image/carte1.png", 10, 0, 0};
  struct card b = {1, "../Image/carte1.png", 20, 20, 0};
  struct card c = {2, "../Image/carte1.png", 30, 40, 0};
  struct card d = {3, "../Image/carte1.png", 40, 60, 0};
  struct card e = {4, "../Image/carte1.png", 50, 80, 0};
  struct card f = {5, "../Image/carte1.png", 60, 10, 0};
  }

 char sprite(void){
  ChargerSprite("../Image/carte1.png");
  ChargerSprite("../Image/carte2.png");
  ChargerSprite("../Image/carte3.png");
  ChargerSprite("../Image/carte4.png");
  ChargerSprite("../Image/carte5.png");
  ChargerSprite("../Image/carte6.png");

  return sprite;
 }



int main (void){


int marge = 30;
int x = marge;
int y = 55;
int i, j;

InitialiserGraphique();
CreerFenetre(10,25,(longueurImage*8 + marge*8 + 20),(largeurImage*6 + marge*6 +55));

for(i = 0; i < 6; i++){
  for (j = 0; j < 8; j++){
    structcard();
    int sprite = ChargerSprite(sprite());
    int aff = AfficherSprite(sprite, x, y);
    x = x + marge + longueurImage;
    aff = aff +1; 
  }
  x = 30;
  y = y + marge + largeurImage;

}


  return EXIT_SUCCESS;
}
