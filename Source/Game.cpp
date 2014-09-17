#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	   int estado = 0;
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		    case 1:ESTADO_INICIANDO:    //INICIALIZAR
			break;
			case 2:ESTADO_MENU:	        //MENU	
			break;
			case 3:ESTADO_JUGANDO:      //JUGAR	
			break;
			case 4:TERMINADO:           //TERMINANDO
		    break;
		    case 5:ESTADO_TERMINANDO:   //FINALIZANDO	
			salirJuego = true;
			break;
		};

    }
	return true;
}
