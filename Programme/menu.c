#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

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
void Grille(int cartex, int cartey); /*initialise la grille de jeu en fonction
 de la difficulté avec des tailles différentes*/
void Retour(void);
void Victoire(void);

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

void Grille(int cartex, int cartey)
{
  srand(time(NULL));
  /*initialise seconde à 0 pour commencer le temps à partir de 0*/
  int seconde = 0; 
  char buf[100];
  unsigned long temps;
  int goon = 1;
 
  int spriterandsize = cartex * cartey,
  spritesize = spriterandsize/2,
  MAX = spriterandsize,
  MIN = 0,
  x = marge,
  y = 70,
  i, 
  j;

  temps = Microsecondes() + CYCLE;
  CreerFenetre(10,25,(longueurImage*cartey + marge*cartey + 20),(largeurImage*cartex + marge*cartex +55));
  ChargerImageFond("../Image/fond.png");

    int sprite[21] = {  
      ChargerSprite("../Image/carte1.png"),
      ChargerSprite("../Image/carte2.png"),
      ChargerSprite("../Image/carte3.png"),
      ChargerSprite("../Image/carte4.png"),
      ChargerSprite("../Image/carte5.png"),
      ChargerSprite("../Image/carte6.png"),
      ChargerSprite("../Image/carte7.png"),
      ChargerSprite("../Image/carte8.png"),
      ChargerSprite("../Image/carte9.png"),
      ChargerSprite("../Image/carte10.png"),
      ChargerSprite("../Image/carte11.png"),
      ChargerSprite("../Image/carte12.png"),
      ChargerSprite("../Image/carte13.png"),
      ChargerSprite("../Image/carte14.png"),
      ChargerSprite("../Image/carte15.png"),
      ChargerSprite("../Image/carte16.png"),
      ChargerSprite("../Image/carte17.png"),
      ChargerSprite("../Image/carte18.png"),
      ChargerSprite("../Image/carte19.png"),
      ChargerSprite("../Image/carte20.png"),
      ChargerSprite("../Image/carte21.png")
    };


    int sprite2 = ChargerSprite("../Image/back.png");

    int spritesRand[spriterandsize]; /*tableau destiné a accueillir les valeurs random de sprite*/
    
    for (i = 0; i < spriterandsize; i ++)
    {     /*incremente le tableau random de 0*/
      
      spritesRand[i] = 0;
    }

    for (i = 0; i < spritesize; i++)
    {  /*boucle dans le tab des sprites pour garder le sprite courant*/
      int current = sprite[i];
      printf("sprite %d : %d\n", i, sprite[i] );
      for (j = 0; j < 2; ) {  /*sort de la boucle si le currentsprite a été placé 2fois dans le tab rand*/
        int ran = (rand() % (MAX - MIN) + MIN);
        if (spritesRand[ran] == 0)
        {  /*le curseur cherche aléatoirement un espace dans le tab*/
          spritesRand[ran] = current;
          j++;
        }
      }
    }

    int grillerand[cartex][cartey];
    int ligne, colonne;
    i = 0;

    for ( ligne = 0; ligne < cartex; ligne++ )
    {
      for (colonne = 0; colonne < cartey; colonne++)
      {
        grillerand[ligne][colonne] = spritesRand[i];
        AfficherSprite(sprite2, x, y);
        x = x + marge + longueurImage;
        i++;
      }
      x = marge;
      y = y + marge + largeurImage;
    }

    int selection = 0, score = 0, selectionx = 0, selectiony = 0;
    bool statut = true; 

    while (goon == 1)
    {
    if (Microsecondes()>temps)
    {
      seconde++;
      ChoisirEcran(1);
      EffacerEcran(CouleurParNom("White"));
      ChargerImageFond("../Image/fond.png");
      snprintf(buf,100,"temps : %5d",seconde);
      EcrireTexte(70,30,buf,1);
      CopierZone(1,0,0,0,500,70,0,0);
      ChoisirEcran(0);
      printf("%d\n", seconde);
      temps = Microsecondes() + CYCLE;
    }

    int i =0;
    x = marge;
    y = 70;

    if(SourisCliquee())
    {
      for(ligne = 0; ligne < cartex; ligne++ )
      {
        for(colonne = 0; colonne < cartey; colonne++)
        {
          if (((_X >= x) && (_X <= x + longueurImage)) && ((_Y >= y) && (_Y <= y + largeurImage)))
          {
            AfficherSprite(spritesRand[i],x, y);
            sleep(1); /*mise en veille du programme de 1sec pour la seconde selection, permet de le voir*/
            printf("clique %d,%d : %d\n", x, y, spritesRand[i] );
            if(selection == 0){ /*stocke la valeur du clique dans selection, ses coordonnées dans selectionx et selectiony*/
              selection = spritesRand[i];
              selectionx = x;
              selectiony = y;
            }
            else {
              /*if(selection == spritesRand[i] && (selectionx != x || selectiony != y) ){ 
                  score++;  
                  printf("Goal !, score : %d\n", score);
              }*/
              if (selection != spritesRand[i]){
                printf("Wrong\n");
                AfficherSprite(sprite2, x, y);  /*si faux, réaffiche le bac par dessus la premi!re selection et la deuxeieme*/
                AfficherSprite(sprite2, selectionx, selectiony);
              }
              else {
                score++;
                 printf("Goal !, score : %d\n", score);
              }
              selection = 0; /*rénitialise les valeurs */
              /*selectionx = 0; 
              selectiony = 0;*/
            }
          }
          x = x + marge + longueurImage;
          i++;
        }
        x = marge;
        y = y + marge + largeurImage;
      }
    } 
    if(score == spritesize){ /* condition de victoire, return 0 pour montrer la fin*/
      goon = 0;  
    }
Retour();
}
FermerGraphique();
Victoire();
}

void Victoire(void){
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
}

void Retour(void)
{
    if (ToucheEnAttente()){
    if (Touche() == XK_Escape)
    {
        FermerGraphique();
        Menu();
    }
   }
}

int main(void)
{ 
    InitialiserGraphique();   /*créer la fenetre */
    CreerFenetre(10,25,1280,720);
    Menu();
    Touche();
    FermerGraphique();

}