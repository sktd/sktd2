#include "tile.h"


map::tile::tile(double px, double py, std::string s, int tp):
	drawable(px, py, s), type(tp)
{
}


map::tile::~tile(void)
{
}

void map::tile::draw(sf::RenderWindow &win)
{
	win.draw(sp);
}

map::tile::tile()
{
}

void map::tile::draw2(sf::RenderWindow &win)
{
	sf::Texture t;
	t.loadFromFile("Grafika/wybrane.png");
	sf::Sprite sp2;
	sp2.setTexture(t);
	sp2.setPosition(get_pos_x(), get_pos_y());
	win.draw(sp2);
}

int map::tile::get_type()
{
	return type;
}

void map::tile::set_type(int t)
{
	type=t;
}