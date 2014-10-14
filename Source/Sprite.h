#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <SDL.h>
#include "SpriteDef.h"
//a un codigo "h" primero se #ifndef para evitar la redundancia
class Sprite
{
	SDL_Surface * image;//Sprite es donde tenemos una imagen
	SDL_Surface * screen;
	SpriteDef spriteDef;//clase spriteDef por que no tiene parametros

public:
	void CargarImagen(char * ruta); // path = ruta del archivo
	//void PintarModulo(int id, int x, int y, int w, int h);
	void PintarModulo(int id, int x, int y);
	Sprite(SDL_Surface * screen);
	~Sprite();
};

#endif