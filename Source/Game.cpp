#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
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
	atexit(SDL_Quit); //14-10-2014 12:00 hr
	nave= new Nave(screen,"../Data/MiNave.bmp");
	//nave->CargarImagen("../Data/MiNave.bmp");

}

// Con esta funci�n eliminaremos todos los elementos en pantalla
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
			/*	switch(estado)
				{
				nave = SDL_LoadBMP("../Data/MiNave.bmp");
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
 **archibos:	SDL_SURFACE = creamos la imagen
				SPRITE = pintamos la imagen
				NVE = le damos movimiento
*/
				
			case Estado::ESTADO_MENU:	//MENU
				     SDL_FillRect(screen, NULL, 0x000000); //(pantalla,toda,color) color en "hexadecimal"
					 // Para pintar toda la pantalla y quede negra "SDL_FillRect(screen, NULL, 0x000000)";
                     keys = SDL_GetKeyState(NULL);
					 if(keys[SDLK_DOWN])
					 {
						 nave->Mover(1);				
					 }					
					 nave->Pintar();//4if con todo
					
					  /*Otra Imagen   
					 if(keys[SDLK_UP])
					 {
				//nave->PintarModulo(0,0,0,64,64); //esas son coordenas de la imagen que se esta leyendo
	        	       nave->PintarModulo(SPRITE_MODULE_MI_NAVE,100,300);  // 290,175-Pantalla de  "640 X 480" despues de estos se sale.Fig = 65 X 65~
					 }*/
			break;
			case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR
			break;
			case Estado::ESTADO_FINALIZADO: //SALIR
				salirJuego = true;
			break;
		};//------------Fin del switch

		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){salirJuego = true;}//Si se detecta una 
			if(event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen); //imprime en pantalla variable screen
    }
	return true;
}
