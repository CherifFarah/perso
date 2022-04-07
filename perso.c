#include "perso.h"

#define vitesse_max 0.8



/** 
 Initialisation 
**/ 



void initialiser_perso (perso *p)
{
p->personnage=IMG_Load("mehdi.png");

//p->vitesse=5;
//p->acceleration=0;

p->rect.x=0;
p->rect.y=100;
p->direction_image=0;

p->rect.w=100;//width
p->rect.h=100;//height
p->X=0;
p->Y=0;

p->pos_perso.x=0;
p->pos_perso.y=0;
p->pos_perso.h=200; 
p->pos_perso.w=100;

}


/** 
  Affichage du perso 
**/ 


void afficher_perso (perso *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->personnage,&p->pos_perso,screen,&p->rect);
}








/** 
  Deplacement 
**/ 

void deplacer (perso *p)
{


//p->rect.x += (vitesse_max) *p->delta;
//printf("%d \n",p->delta);
  if (p->direction == 1) //droite 
  {
    if (p->rect.x >= 1500)
{
      p->rect.x = 1500; // regler la vitesse 
}
    if (p->rect.x < 1500) //limite a droite
    {
p->rect.x += (vitesse_max) *p->delta;
    }
    
  }
  else if (p->direction == 2) //gauche
  {
    if (p->rect.x <= 0)
      p->rect.x = 0;
    if (p->rect.x > 0) //limite a gauche
    {

p->rect.x -= (vitesse_max) *p->delta;
    }
  }
//decelleration 
}


/** 
* Initialisation input 
*/ 


void initialiser_input (Input *I)
{
I->left=0;
I->right=0;

}
/** 
*  Animation du perso 
*/ 


void animerPerso (perso* p){
  p->pos_perso.y =p->direction_image * p->pos_perso.h ; // cad: y = nbre_direction * 100 (hauteur)
  p->pos_perso.x += p->pos_perso.w ;  // cad : x = x + 100 (largeur)
  if (p->pos_perso.x > 100)
  {
    p->pos_perso.x = 0;
  }
if ((p->X==0) && ((p->direction_image == 0) || (p->direction_image == 1)))
{
  p->pos_perso.x= 0;
}

}


/** 
*  Saut du perso
*/ 

void saut (perso *p){
  p->Y= -50;
// parabolique 
}







