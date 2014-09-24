#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.H>
#include <SDL_Image.h>


CGame::CGame(){
	   int estado = ESTADO_INICIANDO;///ACT2: Mal, Falto esto de corregir, aqui va tu estado inicial, cual estado quieres que se ejecute primero.
	   SDL_Surface *screen;
	   if (SDL_Init(SDL_INIT_VIDEO)){
		   printf("Error: %s",SDL_GetError());
		   exit(EXIT_FAILURE);
	   }
	   screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
	   if (screen == NULL){
		   printf("Error: %s",SDL_GetError());
		   exit(EXIT_FAILURE);
	   }
	   //SDL_Flip(screen);
	   SDL_WM_SetCaption("Mi primer Juego",NULL);
	 
	   atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:    //INICIALIZAR
			break;
		case Estado::ESTADO_MENU:	      //MENU	
			break;
		case Estado::ESTADO_JUGANDO:      //JUGAR	
			break;
		case Estado::ESTADO_TERMINANDO:     //TERMINANDO
		    break;
		case Estado::ESTADO_FINALIZANDO:   //FINALIZANDO	
			salirJuego = true;
			break;
		};
		
		SDL_Flip(screen);
    }
	return true;
}
