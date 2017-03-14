#include "Enemigo.h"
#include "Estado.h"
#include "Game.h"



Enemigo::Enemigo(Game* juego, Game::Texturas_t text, int x, int y, bool rap)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 240;  // el problema de que los enemigos se vena alargados esta aqui que habria que acceder a la anchura de la textura segun el tipo de enemigo.
	anchocapa = ancho / 3;

	pimgx = x;
	pimgy = y;

	r = rap;
}


Enemigo::~Enemigo()
{
}

void Enemigo::draw() {
	rect.h = alto;
	rect.w = anchocapa;
	rect.x = pimgx;
	rect.y = pimgy;

	rectA.h = alto;
	rectA.w = anchocapa;
	rectA.x = i;
	rectA.y = 0;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, &rectA, &rect);

}

bool Enemigo::onClick() {
	return true;
}
void Enemigo::update() {

	i += ancho;
	rectA.x = i;
	if (i > Enemigo::ancho) i = 0;

	cont++;
	if (cont >= 5 && pimgx >=745) { // ZAS, En TODA LA BOCA
		cont = 0;
		if (r) pimgx -= 2;
		else pimgx--;
	}
	if (cont >= 5 && pimgx <= 500) {
		cont = 0;
		if (r) pimgx += 2;
		else pimgx++;
	}

}


void Enemigo::move(char c) {

}


