#include "Nave.h"
#include "Config.h"

//constructor y aqui recibe los parametros
Nave:: Nave(SDL_Surface * screen, char *rutaImagen, int x, int y, int module)
{
	moduleUsing = module;
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w = sprite->WidthModule(moduleUsing); //variables para los modulos
	h = sprite->HeightModule(moduleUsing);

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
	sprite->PintarModulo(moduleUsing,x,y);
}

void Nave::MoverDerecha(int posicion)
{
	x += posicion;
}
//-----
void Nave::MoverIzquierda(int posicion)//Nave.h-25;Game.cpp-78;Nave.cpp-86;Nave.cpp-71
{  //Se cambio Mover por MoverDerecha. y lo que esta dentro de lo comentado.
	x -= posicion;
}
void Nave::MoverArriba(int posicion)
{
	y -= posicion;
}
void Nave::MoverAbajo(int posicion)
{
	y += posicion;
}
//-----
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
			   MoverDerecha(posicionBrinco);
			   posicionActual++;
		   }
		else //Terminar la animacion		 
		   {
			   TerminarAnimacion();
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
void Nave::TerminarAnimacion()
{
	 posicionBrinco=0; //Con estos cuatro renglones terminamos la animacion.
	 posicionActual=0;
	 posicionFinal=0;
	 IncrementarStep();
}


