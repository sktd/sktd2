#include "mob.h"


map::mob::mob(double px, double py, std::string s, double vel, double hlth, int wrth, int destination):
	drawable(px, py, s), health(hlth), worth(wrth), velocity(vel), destination(destination)
{
}

map::mob::~mob(void)
{
}

 void map::mob::reduce_health(double hm)
{
}

void map::mob::move()
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

void map::mob::move(double x, double y)
{
	sp.move(x,y);
}

int map::mob::get_destination()
{
	return destination;
}

void map::mob::set_destination(int d)
{
	destination=d;
}
