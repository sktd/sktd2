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
	timeInt=time.asMilliseconds()+10;
	if(timeInt%500<10){
		int destination=int(rand())%4+1;
		Projectile1 *wsk=new Projectile1(get_pos_x()+10, get_pos_y()+10, "pocisk.png", speed, 10, 10, destination);
		projectiles.push_back(wsk);
		clock.restart();
	}

}

void map::tower1::draw(sf::RenderWindow &win)
{
	win.draw(sp);
	it=projectiles.begin();
	while(it!=projectiles.end()){
		if((*it)->get_pos_x()>700||(*it)->get_pos_x()<0||(*it)->get_pos_y()>500||(*it)->get_pos_y()<0){
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
}

void map::tower1::check_collisions(mob &m)
{
	it=projectiles.begin();
	while(it!=projectiles.end()){
		if(m.collision(**it)){
			m.reduce_health((**it).get_damage());
			delete *it;
			projectiles.erase(it);
			break;
		}
		++it;
	}
}
