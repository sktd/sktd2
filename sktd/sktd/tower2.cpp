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
	timeInt=time.asMilliseconds()+11;
	if(timeInt%2000<10){
		Projectile2 *wsk=new Projectile2(get_pos_x(), get_pos_y(), "pocisk_kolowy.png", 1, 0.5, 10);
		projectiles.push_back(wsk);
	}
}

void map::tower2::draw(sf::RenderWindow &win)
{
	win.draw(sp);
	it=projectiles.begin();
	while(it!=projectiles.end()){
		if((*it)->get_scale()>10){
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
			m.reduce_speed((*it)->get_damage());
			/*delete *it;
			projectiles.erase(it);*/
		//	break;
		}
		++it;
	}
}
