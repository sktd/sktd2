#include "tower2.h"


map::tower2::tower2(double px, double py, std::string s, double spd, int cst, double rotation):
	tower( px, py, s, spd, cst ), rotation(rotation)
{
	sp.setOrigin(16,16);
	sp.setPosition ( get_pos_x()+16, get_pos_y()+16 );
}

map::tower2::tower2(double px, double py, std::string s, int cst):
	tower(px,py,s,cst)
{
}


map::tower2::~tower2(void)
{
}

void map::tower2::fire()
{
	time=clock.getElapsedTime();
	timeInt=time.asMilliseconds()+20;
	if(timeInt%600<20){
		int destination=int(rand())%4+1;
		Projectile1 *wsk=new Projectile1(get_pos_x()-5, get_pos_y()-10, "Grafika/fball.png", speed, 10, 10, destination);
		projectiles.push_back(wsk);
		clock.restart();
	}
}

void map::tower2::draw(sf::RenderWindow &win)
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
	sp.setRotation(sp.getRotation()+rotation);
}

void map::tower2::check_collisions(mob &m)
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
