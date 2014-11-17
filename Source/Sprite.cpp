#include "Sprite.h"

void Sprite::CargarImagen(char*ruta){//Aqui es donde cargamos las imagenes de acuerdo a la ruta que pusimos
		image= SDL_LoadBMP(ruta);
		SDL_SetColorKey(image,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(image->format,255,0,0));//hoy15-11-2014
		//Con este SDL_SetColorKey le estamos haciendo transparentes el color rojo de las naves
}

Sprite::Sprite(SDL_Surface * screen)
{
	this->screen = screen;
}

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
}
/*void Sprite::PintarModulo(int id, int x, int y, int w, int h)
{
	SDL_Rect src;
	src.x=x;
	src.y= y;
	src.w= w;
	src.h= h;
	SDL_BlitSurface(image, &src, screen, NULL);

}*/

void Sprite::PintarModulo(int id, int x, int y) //hay que crear un mudulo nuevo e indicar que 
{
	SDL_Rect src;
	src.x = spriteDef.modulos[id].x; //spriteDef.cpp para llamarlo
	src.y = spriteDef.modulos[id].y;
	src.w = spriteDef.modulos[id].w;
	src.h = spriteDef.modulos[id].h;
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(image, &src, screen, &dest);

}

int Sprite::WidthModule(int id)
{
	return spriteDef.modulos[id].w;
}
	int Sprite::HeightModule(int id)
	{
		return spriteDef.modulos[id].h;
	}
