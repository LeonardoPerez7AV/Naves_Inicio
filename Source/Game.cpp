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
}

//ACT3: Mal, falto el metodo "Iniciando()"
void CGame::Iniciando(){
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
	nave= new Nave(screen,"../Data/MiNave.bmp",(WIDTH_SCREEN/2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/);
	enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);
	//ennemigoParabola = -100.0f;
	enemigo->SetStep(4);
	//nave->CargarImagen("../Data/MiNave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	int bandera = 0;

	while (salirJuego == false)
	{
		//Maquina de estados
		switch(estado)
		{
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			
			Iniciando();//ACT3: Mal, falto llamar al metodo iniciando.
		    printf("\n1. ESTADO_INICIANDO");//EXAMEN1
			estado = ESTADO_MENU;//ACT2: Mal falto llamar al siguiente estado
			break;
		case Estado::ESTADO_MENU:	//MENU
			SDL_FillRect(screen, NULL, 0x000000); //(pantalla,toda,color) color en "hexadecimal"
			// Para pintar toda la pantalla y quede negra "SDL_FillRect(screen, NULL, 0x000000)";
			keys = SDL_GetKeyState(NULL);
			enemigo->Actualizar();
			MoverEnemigo();
			if(keys[SDLK_RIGHT] && !esLimitePantalla(nave,BORDE_DERECHO)) //La nave no esta en el limite de screen

			{//en los metodos se nombran con cosas que se pueden leer
				nave->Mover(1);				
			}					
			nave->Pintar();//4if con todo  
			enemigo -> Pintar();//Nave enemigo

		    //Otra Imagen   
		/*	if(keys[SDLK_UP])
			{
			nave->PintarModulo(0,0,0,64,64); //esas son coordenas de la imagen que se esta leyendo
			nave->PintarModulo(SPRITE_MODULE_MI_NAVE,100,300);  // 290,175-Pantalla de  "640 X 480" despues de estos se sale.Fig = 65 X 65~
			}
			 printf("\n2. ESTADO_MENU");*/
		
			break;
		case Estado::ESTADO_JUGANDO:	//JUGAR	
		
			estado = ESTADO_TERMINADO;
			break;
		case Estado::ESTADO_TERMINADO:	//TERMINAR
	
   		 	 //estado = ESTADO_FINALIZADO;
			 
			
			
		  	break;
		case Estado::ESTADO_FINALIZADO: //SALIR
			
		

			getchar();
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

bool CGame::esLimitePantalla(Nave *objeto, int bandera)//metodo para limitar la pantalla
{
	if(bandera & BORDE_IZQUIERDO) //CTRL + ESPACIO// & para valores binarios y 
	   if (objeto->obtenerX() <= 0)//revisar bordes falso o verdadero
	      return true;
	if(bandera & BORDE_SUPERIOR)
    	if(objeto->obtenerY() <= 0) 
	     	return true;
	if(bandera & BORDE_DERECHO)
    	if(objeto->obtenerX() >= (WIDTH_SCREEN-objeto->obtenerW()))
	    	return true;
	if(bandera & BORDE_INFERIOR)
    	if(objeto->obtenerY() >= (HEIGHT_SCREEN-objeto->obtenerH()))
	    	return true;
		return false;// si se cumplen todas las condiciones quiere decir que estamos adentro de la pantalla
}

void CGame::MoverEnemigo()//Metodo para mover al enemigo
{
	// Aqui le damos movimiento x , y
	//if(!esLimitePantalla(enemigo, BORDE_DERECHO))  // Recordar f(x)=x^2  para garficar  f(x) | x^2
	//enemigo->Mover(1,50);  // el if y esto es lo que se cambia para moverlo diferente
	switch(enemigo->ObtenerStepActual())
	{
	 case 0:
		  if(!enemigo->IsRunningAnimacion())
			  enemigo->Mover(1,WIDTH_SCREEN-enemigo->obtenerW());	
			 //  enemigo->IncrementarStep();
			
		break;
	 case 1:
		 enemigo->IncrementarStep();
		break;
	 case 2:
		   if(!enemigo->IsRunningAnimacion())
		 enemigo->Mover(-1,WIDTH_SCREEN-enemigo->obtenerW());
		 // enemigo->IncrementarStep();
		break;
	 case 3:
		  enemigo->IncrementarStep();
		break;

	}
	
	//enemigo->ponerEn(ennemigoParabola*ennemigoParabola,ennemigoParabola);
	//ennemigoParabola+= 0.03f;
}
