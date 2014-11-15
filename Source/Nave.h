#ifndef _NAVE_H_  //para proteger 
#define _NAVE_H_
#include "Sprite.h"


class Nave
{
	//Todas las variables
	int x;
	int y;
	int w;
	int h;
	int posicionActual;//donde esta la nave
	int posicionFinal;//asta donde llegara
	int posicionBrinco;
	int stepActual;
	int stepFinal;
	int moduleUsing; //Modulo en uso. lo utilizamos para la portada
	Sprite *sprite;
public:
	Nave(SDL_Surface * screen, char *rutaImagen, int x, int y, int module);
	~Nave();
	//Aqui se crean todos los metodos
	void Pintar();
	void MoverDerecha(int posicion);
	void MoverIzquierda(int posicion);
	void MoverArriba(int posicion);
	void MoverAbajo(int posicion);
	        //   cant      numero de veces
	void Mover(int brinco, int puntoFinal);
	void SetStep(int stepsFinal);
	void IncrementarStep();
	int  ObtenerStepActual();
	void Actualizar(); //Metodo de ACtualizacion
	bool IsRunningAnimacion();
	void TerminarAnimacion();//Fuerza a terminar la STEP actual de la nave
	int obtenerX();    //metodo para obtener el bvalor de x y y
	int obtenerY();
	int obtenerW();
	int obtenerH();
	void ponerEn(int x, int y);
};

#endif