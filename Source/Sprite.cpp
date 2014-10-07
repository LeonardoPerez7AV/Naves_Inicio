
#include "Sprite.h"

void Sprite::CargarImagen(char * ruta)
{  
		image = SDL_LoadBMP(ruta);	
}

Sprite::Sprite(SDL_Surface * screen)
 {
	this->screen = screen; //this es para inicar que es de la variable de la clase
 }

 Sprite::~Sprite()
 {
	 SDL_FreeSurface(image);
  
 }

 void Sprite::PintarModulo(int id, int x, int y, int w, int h)
 {
	 SDL_Rect src;
	 src.x = x;
	 src.x = y;
	 src.x = w;
	 src.x = h;
	 SDL_BlitSurface(image,&src,screen,NULL);
 }