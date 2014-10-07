//#ifndef __GAME_H__
//#define __GAME_H__
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado{
         ESTADO_INICIANDO,
         ESTADO_MENU,
         ESTADO_JUGANDO,
         ESTADO_TERMINANDO,
         ESTADO_FINALIZANDO
   };

private:
	void Iniciando();
	SDL_Surface * screen;
	Sprite *nave;    //SDL_Surface * nave;
	Estado estado;

};
//#endif