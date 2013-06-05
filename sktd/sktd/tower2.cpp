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
	if(clock.getElapsedTime().asMilliseconds()==100){
		projectile *wsk=new projectile(get_pos_x(), get_pos_y(), "pocisk.png", 10, 10, 10);
		projectiles.push_back(wsk);
	}
}

void map::tower2::draw(sf::RenderWindow &win)
{
	itp=projectiles.begin();
	while(itp!=projectiles.end()){
		(*itp)->move(0.1,0);
		(*itp)->draw(win);
		++itp;
	}
	sp.setRotation(sp.getRotation()+rotation);
	win.draw(sp);

}
