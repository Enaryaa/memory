/* 29/11/2018 */

#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

int main(int argc, char * argv[]){
	int temps;
	int bool = 0; /* condition de sortie de la boucle */
	int carte = 0; /* condition de victoire */

	/*boucle qui initialise le temps qui defile; quitte la boucle lorsque le temps est écoulé (bool == 0) : affiche une page game over et fin de partie */ 
	
	for (temps = 0; temps < 90 && bool == 0; temps++){
		printf("%d\n", temps);
		sleep(1);  

		/* condtion de victoire si bool == 1 du coup carte == 1; toutes les cartes ont été retournées */

		if (carte == 1) {
			bool == 1;
		}
	}

return EXIT_SUCCESS;
}

