#pragma once
#include "game.h"


class Estado: public raizEstado
{
public:
	Estado(Game * j);
	~Estado();

	void draw();
	void update();
	void onClick(){ ; }
	void move(char c){ ; }

protected:

	Game* ptsjuego;

	std::list <raizObjeto*> objetos; // objetos que contiene cada estado
	std::list <raizObjeto*> balas; 

};

