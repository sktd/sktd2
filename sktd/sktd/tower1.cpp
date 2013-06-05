#include "tower1.h"


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
	if(clock.getElapsedTime().asMilliseconds()==1000){
		projectile *wsk=new projectile(get_pos_x(), get_pos_y(), "pocisk_kolowy.png", 10, 10, 10);
		projectiles.push_back(wsk);
	}

}

void map::tower1::draw(sf::RenderWindow &win)
{
	itp=projectiles.begin();
	while(itp!=projectiles.end()){
		(*itp)->set_scale((*itp)->get_scale()+0.1);
		(*itp)->draw(win);
		++itp;
	}
	win.draw(sp);
}
