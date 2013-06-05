#include "projectile.h"


map::projectile::projectile(double px, double py, std::string s, double vel, double dmg, double ang):
	drawable(px, py, s), damage(dmg), angle(ang), velocity(vel)
{
//	scale=1;
}


map::projectile::~projectile(void)
{
}

void map::projectile::move(double x, double y)
{
	sp.move(x,y);
}

double map::projectile::get_scale()
{
	return sp.getScale().x;
}

void map::projectile::set_scale(double sc)
{
	sp.setScale(sc, sc);
}