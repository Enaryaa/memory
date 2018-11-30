
#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

int main(int argc, char * argv[]){

int grille[8][6];
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
      printf("\n");


return EXIT_SUCCESS;
}

