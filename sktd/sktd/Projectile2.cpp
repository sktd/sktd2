#include "Projectile2.h"


map::Projectile2::Projectile2(double px, double py, std::string s, double vel, double dmg, double ang):
	projectile(px, py, s, vel, dmg, ang)
{
}


map::Projectile2::~Projectile2(void)
{
}

double map::Projectile2::get_scale()
{
	return sp.getScale().x;
}

void map::Projectile2::set_scale(double sc)
{
	sp.setScale(sc, sc);
}

void map::Projectile2::draw(sf::RenderWindow &win)
{
	set_scale(get_scale()+0.1);
	move(-1.4, -1.4);
	win.draw(sp);
}