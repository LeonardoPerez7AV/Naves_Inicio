#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	   int estado = ESTADO_INICIANDO;///ACT2: Mal, Falto esto de corregir, aqui va tu estado inicial, cual estado quieres que se ejecute primero.
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

    }
	return true;
}
