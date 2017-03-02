#include "menu.h"
#include "button.h"
#include "play.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBoton, 500, 400, salir));
	objetos.emplace_back(new Button(ptsjuego, Game::TBoton, 200, 400, jugar));
}


Menu::~Menu()
{
}
void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::jugar(Game * jg){
	jg->changeState(new Play(jg));  
}

void Menu::onClick(){
	bool clickeado = false;

	std::list <raizObjeto*>::reverse_iterator it = objetos.rbegin();
	while (!clickeado && it != objetos.rend()){
		if ((*it)->onClick())	clickeado = true;
		it++;
	}

}