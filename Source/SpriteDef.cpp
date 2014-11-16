#include "SpriteDef.h"
#include "Config.h"
//primero libreria

SpriteDef::SpriteDef()//constructor de la clase
{
	modulos[0].id = 0;//MODULO CERO LA DE LA NAVE
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;
	modulos[1].id = 1;//MODULO 1 ES DE LA PORTADA
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;//Tamaño de la pantalla donde estamos trabajando
	modulos[1].h = HEIGHT_SCREEN;//Tamaño de la pantalla donde estamos trabajando
	modulos[2].id = 2;//MODULO 1 ES DE LA PORTADA
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 64;//Ancho nave de enemigo //hoy
	modulos[2].h = 64;//largo de enemigo//hoy
}  //en metodos no lleva ;