#ifndef H_NIVEL1_H
#define H_NIVEL1_H

#include "play.h"
class Nivel1 :
	public Play
{
public:
	Nivel1(Game * j);
	~Nivel1();
	void update();
private:
	int aleatorio, enem, emax, izq;
};


#endif