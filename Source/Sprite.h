#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SDL.h>

class Sprite
{
	SDL_Surface * image;//Sprite es donde tenemos una imagen
	SDL_Surface * screen;

public:
	void CargarImagen(char * ruta); // path = ruta del archivo
	void PintarModulo(int id, int x, int y, int w, int h);
	Sprite(SDL_Surface * screen);
	~Sprite();
};

#endif