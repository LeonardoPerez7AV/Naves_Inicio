#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "C:\Users\leonardo\Documents\Naves_Inicio\Proyecto\Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame() //los cuatro puntos son definiciones estaticas de acceso de objetos METODO=Game() y CLASE=Game
{
	   estado = ESTADO_INICIANDO; //aqui va el estado inicial, es el estado quieres que se ejecute primero.
	   atexit(SDL_Quit);
	
	   if (SDL_Init(SDL_INIT_VIDEO))//******cambio de video por audio
	   {
		   printf("Error: %s",SDL_GetError());
		   exit(EXIT_FAILURE);
	   }
	   //screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
	   screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24,SDL_SWSURFACE);//es son los que van "640,480,24,SDL_SWSURFACE"
	   if (screen == NULL)
	   {
		   printf("Error: %s",SDL_GetError());
		   exit(EXIT_FAILURE);
	}
	SDL_Flip (screen); // este codigo estara provicionalmente aqui.
	SDL_WM_SetCaption( "Mi Primer Juego", NULL);
	nave= new Sprite(screen);
	nave->CargarImagen("../Data/MiNave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false)
	{
            
		//Maquina de estados
		switch(estado)
		{
			case Estado::ESTADO_INICIANDO: //INICIALIZAR
				switch(estado)
				{
			/*	nave = SDL_LoadBMP("../Data/MiNave.bmp");
				SDL_Rect Fuente;
				Fuente.x =90;
				Fuente.y =152;
				Fuente.w =242;
				Fuente.h =76;
				SDL_Rect destino;
				destino.x =100;
				destino.y =100;
				destino.w =100;
				destino.h =100;
				SDL_BlitSurface(nave, &Fuente, screen, &destino);
				SDL_BlitSurface(nave, NULL, screen, NULL);
				SDL_FreeSurface(nave);
*/
				
			case Estado::ESTADO_MENU:	//MENU
                         Iniciando();
                          estado=ESTADO_MENU;
	        break;
			case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR
			break;
			case Estado::ESTADO_FINALIZADO: //SALIR
				salirJuego = true;
			break;
		};
		SDL_Flip(screen); //imprime en pantalla variable screen
    }
	return true;
}
}