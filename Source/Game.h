#include <SDL.h>
#include <SDL_image.h>
#include "Nave.h"



class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();  //ACT2: Mal, Aqui dejaste un error, tu codigo debe ser compilable correctamente.
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO,
		};

private:
	void Iniciando();
	void MoverEnemigo();//Metodo para mover al enemigo
	bool esLimitePantalla(Nave *objeto, int bandera);//metodo para limitar la pantalla

	Uint8 *keys;//esta variable nos servira para ver las teclas
	SDL_Event event;//La variable event de tipo evento de SDL nos sirve para

	SDL_Surface *screen;
	Nave *nave;      // La nave Nave y enemigo son las naves
	Nave *enemigo;
	Estado estado;

	float ennemigoParabola;
};