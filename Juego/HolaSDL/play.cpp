#include "play.h"
#include "estado.h"
#include "personaje.h"
#include "bala.h"
#include "enemigo.h"
#include "tren.h"
#include "barraHP.h"

#include <string>
#include<stdlib.h> // para nms aleatorios
#include<time.h>

Play::Play(Game * j) : Estado(j)
{
	//srand(time(NULL));
	initObjects();
}


Play::~Play()
{
	
}

bool Play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)

	train = new Tren(ptsjuego, Game::TTren, 50, 0, " ");// en el último hueco poner como string tipo de vagón
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 350);
	TrainHp = new barraHP(ptsjuego, Game::TBarra, 10, 0, 0);


	//objetos.emplace_back(train); 
	//objetos.emplace_back(player);
	//objetos.emplace_back(TrainHp);


	return true;
}

void Play::freeObjects() {
	
}
void Play::onClick(){
	//objetos[0]->onClick();
	balas.emplace_back(new Bala(ptsjuego, Game::TPersonaje, player->getx(), player->gety(), player->getMira()));
}
void Play::update() {  
	for (std::list <raizObjeto*>::iterator itO = objetos.begin();
		itO != objetos.end(); itO++) {

		
		if ((*itO) != nullptr  && (*itO)->getId() == 'E'
			&& (*itO)->getx() >= 520 && (*itO)->getx() <= 775) {// detecta zombis que quitan vida al tren
			TrainHp->move('h');
		}
		for (std::list <raizObjeto*>::iterator itB = balas.begin();
			itB != balas.end(); itB++) {
			// muerte por colisión de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
			// un booleano que identifique entre balas y sombis
			if ((*itO) != nullptr && (*itB) != nullptr &&
				((*itO)->getx() - (*itB)->getx()) <= 30 && ((*itO)->getx() - (*itB)->getx()) >= -30 &&
				 ((*itO)->gety() - (*itB)->gety()) <= 40 && ((*itO)->gety() - (*itB)->gety()) >= -40) {

			    delete *itO;
			   *itO = nullptr;
				delete *itB;
				*itB = nullptr;
		     }
		}
		
		
		
	}
	aleatorio = rand() % 10000; //generar zombies aleatorios
	raizObjeto::Direccion dir;
	if (aleatorio >= 9980) {
		izq = rand() % 2;
		if (izq == 0) {
			dir.set(1, 0);
			objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 0, rand() % 500 + 50, dir));
		}
		else {
			dir.set(-1, 0);
			objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 1300, rand() % 500 + 50, dir));
		}
	}
	Estado::update();
}

void Play::move(char c){
	player->move(c);
}