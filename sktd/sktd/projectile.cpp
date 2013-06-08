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

void map::projectile::move(int destination)
{
	switch(destination){
	case 1:
		sp.move(velocity, 0);
		break;
	case 2:
		sp.move(-velocity, 0);
		break;
	case 3:
		sp.move(0, velocity);
		break;
	case 4:
		sp.move(0, -velocity);
		break;
	}
}
