#include "tower.h"


map::tower::tower(double px, double py, std::string s, double spd, int cst):
	drawable(px, py, s), speed(spd), cost(cst), pos_x(px), pos_y(py)
{
}

map::tower::tower(double px, double py, std::string s, int cst):
	drawable(px,py,s), cost(cst)
{
}

map::tower::~tower(void)
{
}

void map::tower::fire()
{
	/*if(clock.getElapsedTime().asMilliseconds()==100){
		itp=projectiles.begin();
		projectile *wsk=new projectile(pos_x+5, pos_y+5, "pocisk.png", 0.1,3,3);
		projectiles.insert(itp, wsk);
		clock.restart();
	}*/
}

int map::tower::get_cost()
{
	return cost;
}


