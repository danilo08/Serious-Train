#pragma once
#include "objeto.h"
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Game::Texturas_t text, int x, int y, Direccion dir);
	~Enemigo();
	void draw();
	void update();	
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'E'; }
private:
	Direccion _dir;
	//int cont = 0;
	int vel = 1;
	SDL_Rect rect;
};

