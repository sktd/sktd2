#include "end_game.h"


menu::end_game::end_game(double px, double py, std::string s):
	button(px, py, s)
{
}


menu::end_game::~end_game(void)
{
}

//void menu::end_game::draw(sf::RenderWindow win){
//	win.draw(sp);
//}

void menu::end_game::push(sf::RenderWindow &win, int &game_state)
{
	game_state=0;
	win.close();
}