#include "tower1.h"
#include <stdlib.h>


map::tower1::tower1(double px, double py, std::string s, double spd, int cst):
	tower(px,py,s,spd,cst)
{
}

map::tower1::tower1(double px, double py, std::string s, int cst):
	tower(px, py, s, cst)
{
}


map::tower1::~tower1(void)
{
}

void map::tower1::fire(){
	time=clock.getElapsedTime();
	timeInt=time.asMilliseconds()+21;
	if(timeInt%1000<20){
		Projectile2 *wsk=new Projectile2(get_pos_x()+10, get_pos_y()+10, "Grafika/kolowy2.png", 1, 0.5, 10);
		projectiles.push_back(wsk);
	}

}

void map::tower1::draw(sf::RenderWindow &win)
{
	win.draw(sp);
	it=projectiles.begin();
	while(it!=projectiles.end()){
		if((*it)->get_scale()>0.8){
			delete (*it);
			projectiles.erase(it);
			break;
		}
		++it;
	}
	it=projectiles.begin();
	while(it!=projectiles.end()){
		(*it)->draw(win);
		++it;
	}
	//sp.setRotation(sp.getRotation()+rotation);
}

void map::tower1::check_collisions(mob &m)
{
	it=projectiles.begin();
	while(it!=projectiles.end()){
		if(m.collision(**it)){
			m.reduce_speed((*it)->get_damage());
		}
		++it;
	}
}
