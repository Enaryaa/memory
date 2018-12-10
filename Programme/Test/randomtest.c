#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>
#include<time.h>

int main (void){

const int MAX = 7, MIN = 0;
srand(time(NULL));    

char *sprite[4] = {"../Image/carte1.png", "../Image/carte2.png", "../Image/carte3.png", "../Image/carte4.png"};
int i, j;
char *spriterand[8];
int ran;

char *currentsprite;
char *currentpos;

for (i = 0; i < 4; i++){   /*boucle dans le tab des sprites pour garder le sprite courant*/
	currentsprite = sprite[i];
	for (j = 0; j <= 2; ){ /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
		ran = (rand() % (MAX - MIN) + MIN);
		currentpos = spriterand[ran];
		printf("%s\n", currentpos );
		if( currentpos == NULL){ /*le curseur cherche aléatoirement un espace dans le tab*/
			spriterand[ran] = currentsprite; 
			j++;
		}
	}
}
/* le premier for test toutes les valeurs de sprite[], à la position 0 il va entrer dans le 2e for
pour voir si le currentsprite a été placé 2x de facon aléatoire dans le tableau spriterand. 
alors si spriterand[ran] == NULL, ca veut dire quà la position ran du tableau (aléatoire), il est vide
et on va alors stocker le sprite courant une première fois. j s'incrémente car j compte le nombre de 
fois que le current sprite a été mis.
une fois j = 2, on sort de la boucle pr tester la seconde valeur du tebleau de sprite, et on refait la meme */

printf("%s", spriterand[0]);

    return EXIT_SUCCESS;
}
