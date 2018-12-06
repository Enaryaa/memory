#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

struct card
{
  int id;
  char sprite[24];
  int x;
  int y;
  int isReturned;
};

int main (void){

const int MAX = 4, MIN = 1;
srand(time(NULL));    
int ran = (rand() % (MAX - MIN) + MIN);

char sprite[4] = {"../Image/carte1.png", "../Image/carte2.png", "../Image/carte3.png", "../Image/carte4.png"}
int i;









    return EXIT_SUCCESS;
}
