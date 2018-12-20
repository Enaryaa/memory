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
void Victoire(void); /* apres que le jeu soit fini, affiche une fenetre de victoire qui ramène au menu principal*/
void Facile(void); /*permet de selectionner la grille facile*/
void Normal(void); 
void Difficile(void);
void Regle(void); /*affiche une fenetre avec les règles du jeu*/
void Grille(int cartex, int cartey); /*initialise la grille de jeu en fonction
 de la difficulté avec des tailles différentes*/

int main(void){ 
    InitialiserGraphique();   /*créer la fenetre */
    CreerFenetre(10,25,1400,720);
    Menu();
    Touche();
    FermerGraphique();
}

void Menu(){
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
      SourisCliquee();
      if ( (_X >= 1025) && (_X <= 1095) && (_Y >= 645) && (_Y <= 715) )
      {
        Menu();
      }
    }
  }

void Facile(){
    /*grille facile*/
    Grille(4,5);
    Victoire();
}

void Normal(){
    /*grille normal*/
    Grille(5,6);
    Victoire();
}

void Difficile(){
    /*grille difficile*/
    Grille(5,8);
    Victoire();
}

void Victoire(void){
    while (!SourisCliquee())
    {
      ChargerImageFond("../Image/victoire.png");
      SourisCliquee();
      if ( (_X >= 1010) && (_X <= 1210) && (_Y >= 545) && (_Y <= 645) )
      {
        Menu();
      }
  }
}