#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	   estado = ESTADO_INICIANDO;                        ///ACT2: Mal, Falto esto de corregir, aqui va tu estado inicial, cual estado quieres que se ejecute primero.
	   atexit(SDL_Quit);
	     //int estado = 0;
	   //SDL_Surface *screen;
	 
	   if (SDL_Init(SDL_INIT_VIDEO)<0)
	   {
		   printf("Error: %s",SDL_GetError());
		   exit(EXIT_FAILURE);
	   }
	   screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
	   if (screen == NULL)
	   {
		   printf("Error: %s",SDL_GetError());
		   exit(EXIT_FAILURE);
	   }
	   SDL_Flip(screen);
	   SDL_WM_SetCaption("Mi primer Juego",NULL);
	 
	  // atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	SDL_Quit();
	/*if (SDL_Init( SDL_INIT_VIDEO )){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);		}		screen = SDL_SetVideoMode( 640, 480, 24, SDL_SWSURFACE );
		if (screen == NULL)
		{
			printf("Error %s ", SDL_GetError());
			exit(EXIT_FAILURE);

		}
			SDL_WM_SetCaption( "Mi primer Juego", NULL );
			SDL_Flip(screen);  */

}


bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado)
		{
		case Estado::ESTADO_INICIANDO:    //INICIALIZAR
			//Iniciando();
			{
			    	nave = SDL_LoadBMP("../Data/MiNave.bmp");//los dos puntos significa una carpeta anterior como en cmd
				                                         //propiedades de salida-directorio de salida/las imagenes se encuantran en la carpeta data
			     // nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/umi.jpg","rb"));
			   	// nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/umi.jpg","rb"));
				//  nave = IMG_LoadPNG_RW(SDL_RWFromFile("../Data/umi.png","rb"));
				//  nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/umi.jpg","rb"));
				   SDL_Rect fuente;
				   fuente.x = 90;
				   fuente.y = 152;
				   fuente.w = 242;
				   fuente.h = 76;
					   SDL_Rect destino;
				   destino.x = 100;
				   destino.y = 100;
				   destino.w = 100;
				   destino.h = 100;

				   SDL_BlitSurface(nave, &fuente, screen, &destino);
				   SDL_BlitSurface(nave,NULL,screen,NULL);
				                   //fuente   // destino
     			   SDL_FreeSurface(nave);
			}
			//estado = Estado::ESTADO_MENU;

			//break;
		case Estado::ESTADO_MENU:	      //MENU	
			break;
		case Estado::ESTADO_JUGANDO:      //JUGAR	
			break;
		case Estado::ESTADO_FINALIZANDO:  //FINALIZANDO	 
		    break;
		case Estado::ESTADO_TERMINANDO:   //TERMINANDO
			salirJuego = true;
			break;
		};
		
		SDL_Flip(screen);//todo lo que llega aqui lo imprime
    }
	return true;
}
