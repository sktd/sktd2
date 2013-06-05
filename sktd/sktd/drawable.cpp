#include "drawable.h"


ent::drawable::drawable(double px, double py, std::string s)
{
	t.loadFromFile(s);
	sp.setTexture(t);
	sp.setPosition(px,py);
}

ent::drawable::drawable()
{
}

ent::drawable::~drawable(void)
{
}

void ent::drawable::draw(sf::RenderWindow &win)
{
	win.draw(sp);
}


double ent::drawable::get_size_x()
{
	return t.getSize().x;
}

double ent::drawable::get_size_y()
{
	return t.getSize().y;
}

double ent::drawable::get_pos_x()
{
	return sp.getPosition().x;
}

double ent::drawable::get_pos_y()
{
	return sp.getPosition().y;
}