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


void Menu(void);  /*affiche le menu principal*/
void Facile(void); /*permet de selectionner la grille facile*/
void Normal(void); 
void Difficile(void);
void Regle(void); /*affiche une fenetre avec les règles du jeu*/
void Victoire(void);
void Grille(int cartex, int cartey); /*initialise la grille de jeu en fonction
 de la difficulté avec des tailles différentes*/
/*void Retour(void);*/

int main(void)
{ 
    InitialiserGraphique();   /*créer la fenetre */
    CreerFenetre(10,25,1280,720);
    Menu();
    Touche();
    FermerGraphique();
}

void Menu()
{
    ChargerImageFond("../Image/projet.png"); 
    /*permet de connaitre la position actuelle du curseur */
    SourisPosition();
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
    }
}

void Regle(void){
    while (!SourisCliquee())
    {
      ChargerImageFond("../Image/regle22.png");
      DessinerRectangle(950,563,100,63);
      SourisCliquee();
      if ( (_X >= 950) && (_X <= 1050) && (_Y >= 563) && (_Y <= 616) )
        /*bouton a ajouter en sprite*/
      {
        Menu();
      }
    }
  }

void Facile()
{
    /*grille facile*/
    FermerGraphique();
    InitialiserGraphique(); 
    Grille(4,5);
    Victoire();
}

void Normal()
{
    /*grille normal*/
    FermerGraphique();
    InitialiserGraphique();
    Grille(5,6);
    Victoire();
}

void Difficile(){
    /*grille difficile*/
    FermerGraphique();
    InitialiserGraphique();
    Grille(5,8);
    Victoire();
}

void Victoire(void){
    InitialiserGraphique();
    CreerFenetre(10,25,1280,720); 
    ChargerImageFond("../Image/fond.png");
    while (!SourisCliquee())
    {
      DessinerRectangle(950,563,100,63);
      if(SourisCliquee()){
      if ( (_X >= 950) && (_X <= 1050) && (_Y >= 563) && (_Y <= 616) )
      {
        Menu();
      }
    }
  }
}

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