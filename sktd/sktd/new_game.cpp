#include "new_game.h"


menu::new_game::new_game(double px, double py, std::string s):
	button(px, py, s)
{
}


menu::new_game::~new_game(void)
{
}
//
//void menu::new_game::draw(sf::RenderWindow win){
//	win.draw(sp);
//}

void menu::new_game::push(sf::RenderWindow &win, int &game_state)
{
	game_state=2;
	win.close();
}