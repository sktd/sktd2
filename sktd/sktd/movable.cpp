#include "movable.h"


ent::movable::movable(double px, double py, std::string s, double vel):
	velocity(vel)
{
	t.loadFromFile(s);
	sp.setTexture(t);
	sp.setPosition(px,py);
}

ent::movable::movable(void)
{
}

ent::movable::~movable(void)
{
}

void ent::movable::move()
{
	sp.move(velocity,0);
}

void ent::movable::move(double x, double y)
{
	sp.move(x,y);
}

void ent::movable::draw(sf::RenderWindow &win)
{
	win.draw(sp);
}

bool collide(ent::movable &a, ent::movable &b)
{
	if(a.get_pos_x()>b.get_pos_x()&&b.get_pos_x()+b.get_size_x()>a.get_pos_x()&&a.get_pos_y()>b.get_pos_y()&&b.get_pos_y()+b.get_size_y()>a.get_pos_y())
		return true;
	else
		return false;
}