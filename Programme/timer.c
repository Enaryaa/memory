    #include<stdio.h>
    #include<stdlib.h>
    #include<graph.h>
    #include<math.h>

    #define CYCLE 1000000L


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
                EcrireTexte(100,100,buf,0);
                snprintf(buf,100,"temps : %0d",seconde);
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