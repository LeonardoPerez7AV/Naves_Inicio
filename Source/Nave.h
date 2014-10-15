#ifndef _NAVE_H_  //para proteger 
#define _NAVE_H_
#include "Sprite.h"


class Nave
{
	int x;
	int y;
	Sprite *sprite;
public:
	Nave(SDL_Surface * screen, char *rutaImagen);
	~Nave();
	void Pintar();
	void Mover(int posicion);
};

#endif