#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


#define G 10

int main()
{

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(1600, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	SDL_WM_SetCaption("perso", NULL); // titre de fenetre

	Input I;
	perso p;

	SDL_Event event;
	SDL_Surface *back;
/** 

* @brief Initialisation 
*/ 

	initialiser_perso(&p);
	initialiser_input(&I);

	//initialiser_perso(&p2);
	//initialiser_input(&I2);

	bool running = true;
	back = IMG_Load("BG_perso.jpg"); 


	while (running)
	{	p.tprev= SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:  

				running = false;
				break;
			case SDL_KEYDOWN: 
				switch (event.key.keysym.sym)
				{

				case SDLK_LEFT: 
					I.left = 1;

					break;
				case SDLK_RIGHT:  
					I.right = 1;
					break;

				
				case SDLK_SPACE:  //bouton espace pour sauter 
					if (p.rect.y == 545)
					{
						saut(&p);
					}
					break;
				
				}
				break;
			case SDL_KEYUP:  
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					
					for (i=0.8;i=0;i=i-0.01)
					{
					p.rect.x += i *p.delta;
					}
					i=0;
						printf("%d \n",p.rect.x);
					I.right = 0;
					p.X = 0;
					break;
				case SDLK_LEFT:
					I.left = 0;
					p.X = 0;
					break;
				
				}
				break;
			}
		}

		if (I.right == 1)
		{
			p.X++;
			//p.X += p.X * 
			//printf("%f \n",p.X);
			p.direction=1;
			deplacer(&p);
			p.direction_image = 0;
		}
		else if (I.left == 1)
		{
			p.X++;
			p.direction=2;
			deplacer(&p);
			p.direction_image = 1;
		}

		p.rect.y += p.Y;
		p.Y += G; //gravite
		if (p.rect.y > 545)
		{
			p.Y = 0;
			p.rect.y = 545;
		}//fin p1
		
                 

		animerPerso(&p);
		
		SDL_BlitSurface(back, NULL, screen, NULL);
		afficher_perso(&p, screen);
		

		SDL_Flip(screen);
		p.delta = SDL_GetTicks() - p.tprev;
		
	}
	
}
