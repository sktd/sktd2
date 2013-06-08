#include "Projectile1.h"


map::Projectile1::Projectile1(double px, double py, std::string s, double vel, double dmg, double ang, int dest):
	projectile(px, py, s, vel, dmg, ang), destination(dest)
{
}


map::Projectile1::~Projectile1(void)
{
}

void map::Projectile1::draw(sf::RenderWindow &win)
{
	move(destination);
	win.draw(sp);
}
