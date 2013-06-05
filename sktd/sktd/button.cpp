#include "button.h"


menu::button::button(double px, double py, std::string s):
	drawable(px, py, s)
{
}


menu::button::~button(void)
{
}

void menu::button::draw(sf::RenderWindow &win)
{
	win.draw(sp);
}

void menu::button::draw2(sf::RenderWindow &win)
{
	sf::Texture t;
	t.loadFromFile("ob.png");
	sf::Sprite sp2;
	sp2.setTexture(t);
	sp2.setPosition(get_pos_x()-5, get_pos_y()-5);
	win.draw(sp2);
}
