#pragma once
#include "Estado.h"
#include "Personaje.h"
#include "Vagon.h"
#include "BarraHP.h"

class Play: public Estado
{
public:
	Play(Game * j);
	~Play();

	void onClick();
	void draw();
	void update();
	void move(char c);
	void diparaVagon(char tip, int pmx, int pmy);
	char getEst(){ return 'P'; }

private:
	int izq;
	int aleatorio;
	Personaje* player;
	barraHP* TrainHp;
	Vagon* vagon;

	int vag = 5;
	bool dest;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

	std::vector <RaizObjeto*> balas; // TODO mirad estándares de código
	std::vector <RaizObjeto*> tren; // TODO mirad estándares de código

	int emax, enem;
	int killed;
};

