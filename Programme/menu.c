#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include"grille.h"

#define longueurImage 95
#define largeurImage 95
#define marge 40
#define CYCLE 1000000L
int goon = 0;

/*void Retour(void);
void Victoire(void);*/
void Menu(void);  /*affiche le menu principal*/
void Facile(void); /*permet de selectionner la grille facile*/
void Normal(void); 
void Difficile(void);
void Regle(void); /*affiche une fenetre avec les règles du jeu*/
void Grille(int cartex, int cartey); /*initialise la grille de jeu en fonction
 de la difficulté avec des tailles différentes*/



void Regle(void){
    goon = 4;
    while(goon == 4)
  {
    while (!SourisCliquee())
    {
      ChargerImageFond("../Image/regle22.png");
      DessinerRectangle(950,563,100,63);
      SourisCliquee();
      if ( (_X >= 950) && (_X <= 1050) && (_Y >= 563) && (_Y <= 616) )
        /*bouton a ajouter en sprite*/
      {
        goon = 0;
        Menu();
      }
    }
  }
}

void Facile()
{
    goon = 1; /*grille facile*/
    FermerGraphique();
    InitialiserGraphique(); 
    Grille(4,5);
    
}

void Normal()
{
    goon = 2; /*grille normal*/
    FermerGraphique();
    InitialiserGraphique();
    Grille(5,6);
    
}

void Difficile(){
    goon = 3;/*grille difficile*/
    FermerGraphique();
    InitialiserGraphique();
    Grille(5,8);
    
    
}

void Menu()
{

    InitialiserGraphique();   /*créer la fenetre */
    CreerFenetre(10,25,1280,720);

    ChargerImageFond("../Image/projet.png"); 

    /*DessinerRectangle(770,350,63,63);
    DessinerRectangle(620,445,63,63);
    DessinerRectangle(810,555,63,63);
    DessinerRectangle(159,294,245,242);*/
    SourisPosition();
        /*permet de connaitre la position actuelle du curseur */

    while (goon == 0)
    {
    
        SourisCliquee();
        if ( (_X >= 770) && (_X <= 833) && (_Y >= 350) && (_Y <= 413) ) /*si l'utilisateur clique dans cette surface 
        (qui correspond a un bouton) alors on ferme la fenetre actuelle pour en ouvrir une autre contenant les différentes grilles de jeu*/
        {
            Facile();
        }
        else if ( _X >= 620 && _X <= 683 && _Y >= 445 && _Y <= 508 )
        {
            Normal();
        }
        else if ( _X >= 810 && _X <= 873 && _Y >= 555 && _Y <= 618 )
        {
            Difficile();
        }
        else if ( _X >= 159 && _X <= 404 && _Y >= 294 && _Y <= 586 )
        {
            Regle();
            SourisCliquee();
        }
        /*else if*/
    }
}


/*void Victoire(void){
    InitialiserGraphique();
    CreerFenetre(10,25,1280,720);
    while (!SourisCliquee())
    {
      DessinerRectangle(950,563,100,63);
      SourisCliquee();
      if ( (_X >= 950) && (_X <= 1050) && (_Y >= 563) && (_Y <= 616) )
      {
        FermerGraphique();
        Menu();
      }
    }
}*/

/*void Retour(void)
{
    if (ToucheEnAttente()){
    if (Touche() == XK_Escape)
    {
        FermerGraphique();
        Menu();
    }
   }
}*/

int main(void)
{ 

    
    Menu();
    

    Touche();
    FermerGraphique();

}