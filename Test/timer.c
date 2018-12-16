#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>

#define CYCLE 1000000L
#define longueurImage 95
#define largeurImage 95


    void timer(void)
    {
        
        unsigned long Microsecondes(), temps;
        char buf[100];
        int seconde = 0;        /*initialise seconde à 0 pour commencer le temps à partir de 0*/
        int goon = 1;

        InitialiserGraphique();   /*créer la fenetre */
        CreerFenetre(200,190,1280,720);

        temps = Microsecondes() + CYCLE;

        while (goon == 1)
        {
  
            if (Microsecondes()>temps){
                seconde++;                              /* compte le nombre de seconde*/
                temps = (Microsecondes()+CYCLE);
                EffacerEcran(CouleurParNom("White")); /*permet de rafraichir l'ecran*/
                EcrireTexte(((longueurImage*8 + 30*8 + 20)/2),30,buf,1);
                snprintf(buf,100,"temps : %5d",seconde);
                printf("%d", seconde);
            }
        }

    }

int main (void) 
{
    timer();

    return EXIT_SUCCESS;
}
            /*temps = ((Microsecondes()-CYCLE)*pow(10,-6));
            printf("%d\n", temps);*/