#include "Nave.h"
#include "Config.h"

Nave:: Nave(SDL_Surface * screen, char *rutaImagen, int x, int y)//constructor
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w = sprite->WidthModule(0); //variables para los modulos
	h = sprite->HeightModule(0);

	this->x=x;//Aqui se corto la direccion y se coloco en Game.cpp nave
    this->y=y;//
	stepActual=0;
	posicionBrinco=0;
	posicionActual=0;
}

Nave::~Nave()
{
	delete sprite;
}

void Nave::Pintar()
{
	sprite->PintarModulo(0,x,y);
}

void Nave::Mover(int posicion)
{
	x += posicion;
}

int Nave::obtenerX()
{
	return x;
}

int Nave::obtenerY()
{
	return y;
}

int Nave::obtenerW()
{
	return w;
}
int Nave::obtenerH()
{
	return h;
}

void Nave::ponerEn(int x, int y)
{
	this->x=x;
	this->y=y;
}

void Nave::Mover(int brinco, int puntoFinal)
{
	if(posicionBrinco<=0)
	{
	  posicionBrinco = brinco;
	  posicionFinal = puntoFinal;
	}
}

void Nave::Actualizar()
{
	if(posicionBrinco != 0)
	{
		if(posicionActual <= posicionFinal)
		   {
			   Mover(posicionBrinco);
			   posicionActual++;
		   }
		else
		 
		   {
			    posicionBrinco=0;
				posicionActual=0;
				posicionFinal=0;
				IncrementarStep();
		   }
	}
}

void Nave::SetStep(int stepsFinal) //Aqui se habilitan los metodos
{
	this->stepFinal = stepsFinal;
}
void Nave::IncrementarStep()
{
	stepActual++;
		if(stepActual >= stepFinal)
			stepActual=0;
}
int  Nave::ObtenerStepActual()
{
	return stepActual;
}

bool Nave::IsRunningAnimacion()
{
	if(posicionBrinco==0)
		return false;
	else
		return true;
}


