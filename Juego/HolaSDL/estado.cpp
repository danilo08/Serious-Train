#include "estado.h"
#include "play.h"

Estado::Estado(Game * j)
{
	ptsjuego = j;
}


Estado::~Estado()
{
}

//Recorre la lista de objetos llamando al draw de cada uno, lo mismo con la lista de balas
void Estado::draw() {
	
	for (auto o : objetos)
		o->draw();
	for (auto b : balas)
		b->draw();

	/////////////////////OBSOLETE!///////////////////////////////////
	/*for (std::list<raizObjeto*>::iterator objsIt = objetos.begin();
	objsIt != objetos.end(); objsIt++) {
	if ((*objsIt) != nullptr)
	(*objsIt)->draw();
	}
	for (std::list<raizObjeto*>::iterator balasIt = balas.begin();
	balasIt != balas.end(); balasIt++) {
	if ((*balasIt) != nullptr)
	(*balasIt)->draw();
	}*/
}




//Recorre la lista de objetos llamando al update de cada uno, lo mismo con la lista de balas
void Estado::update() {

	for (auto o : objetos)
		o->update();
	for (auto b : balas)
		b->update();

	/////////////////////OBSOLETE!///////////////////////////////////
	/*for (std::list<raizObjeto*>::iterator objsIt = objetos.begin();
	objsIt != objetos.end(); objsIt++) {
	if ((*objsIt) != nullptr)
	(*objsIt)->update();
	}
	for (std::list<raizObjeto*>::iterator balasIt = balas.begin();
	balasIt != balas.end(); balasIt++) {
	if ((*balasIt) != nullptr)
	(*balasIt)->update();
	}*/
	
}

