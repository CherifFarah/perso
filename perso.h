#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

int i;
typedef struct perso
{

SDL_Rect pos_perso;
int direction_image; 
/*
0:droite
1:gauche
2:attack droite
3:attack gauche
*/

SDL_Surface *personnage;
SDL_Rect rect;
Uint32 delta,tprev;
float X,Y;//les vitesses (horizontale et verticale)
int direction ; 

//double vitesse acceleration;
}perso;

typedef struct Input
{
 int left,right,jump;

} Input;

void initialiser_perso (perso *p);
void afficher_perso (perso *p,SDL_Surface *screen);


void animerPerso (perso* p);

void deplacer (perso *p);
void initialiser_input (Input *I);

void saut (perso *p);





 #endif
