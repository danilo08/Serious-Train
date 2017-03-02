#include "estado.h"
#include "play.h"

Estado::Estado(Game * j)
{
	ptsjuego = j;
}


Estado::~Estado()
{
}

void Estado::draw() {

	for (std::list<raizObjeto*>::iterator objsIt = objetos.begin(); 
		objsIt != objetos.end(); objsIt++) {
		if ((*objsIt) != nullptr)
		   (*objsIt)->draw();
	}	
	for (std::list<raizObjeto*>::iterator balasIt = balas.begin();
		balasIt != objetos.end(); balasIt++) {
		if ((*balasIt) != nullptr)
			(*balasIt)->draw();
	}
}





void Estado::update() {
	for (std::list<raizObjeto*>::iterator objsIt = objetos.begin();
		objsIt != objetos.end(); objsIt++) {
		if ((*objsIt) != nullptr)
			(*objsIt)->update();
	}
	for (std::list<raizObjeto*>::iterator balasIt = balas.begin();
		balasIt != objetos.end(); balasIt++) {
		if ((*balasIt) != nullptr)
			(*balasIt)->update();
	}
}

