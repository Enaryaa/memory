#include<stdlib.h>
#include<graph.h>
 
int main()
{
    InitialiserGraphique();
    CreerFenetre(10,10,500,500);
    int touche;
    while(touche != 113) {

    	touche = Touche();
    }
    FermerGraphique();
    return EXIT_SUCCESS;
}
