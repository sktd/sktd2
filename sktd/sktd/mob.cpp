#include "mob.h"

map::mob::mob(double px, double py, std::string s, double vel, double hlth, int wrth, int destination):
	drawable(px, py, s), health(hlth), worth(wrth), velocity(vel), destination(destination)
{
	ready=false;
	is_reduced=false;
}

map::mob::~mob(void)
{
}

 void map::mob::reduce_health(double hm)
{
	health-=hm;
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

//int map::mob::get_id()
//{
//	return id;
//}

bool map::mob::is_ready()
{
	return ready;
}

void map::mob::start()
{
	ready=true;
}

double map::mob::get_health()
{
	return health;
}

int map::mob::get_worth()
{
	return worth;
}

void map::mob::reduce_speed(double how_much)
{
	if(is_reduced==false){
		velocity-=how_much;
		is_reduced=true;
	}
}

bool map::mob::isReduced()
{
	return is_reduced;
}

bool map::mob::collision(projectile &p)
{
	double x1=(*this).get_pos_x();
	double y1=(*this).get_pos_y();
	double x2=p.get_pos_x();
	double y2=p.get_pos_y();
	double l1=(*this).get_size_x();
	double h1=(*this).get_size_y();
	double l2=p.get_size_x();
	double h2=p.get_size_y();

	if(x1+l1>x2&&x1<x2&&y1+l1>y2&&y1<y2)
		return true;
	if(x1+l1>x2&&x1<x2&&y1+l1>y2&&y1<y2+l2)
		return true;
	if(x1>x2&&x1<x2+l2&&y1+l1>y2&&y1<y2)
		return true;
	if(x1+l1>x2&&x1<x2&&y1+l1>y2&&y1<y2+l2)
		return true;


	return false;

}
