#include "Projectile2.h"


map::Projectile2::Projectile2(double px, double py, std::string s, double vel, double dmg, double ang):
	projectile(px, py, s, vel, dmg, ang)
{
	set_scale(0.05);
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
	set_scale(get_scale()+0.01);
	move(-2.8, -2.8);
	win.draw(sp);
}