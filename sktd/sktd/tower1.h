#pragma once
#include "tower.h"
#include "Projectile1.h"
//#include "player_console.h"
//#include "mob.h"
namespace map
{
	class tower1 :
		public tower
	{
	public:
		tower1(double px, double py, std::string s, double spd, int cst);
		tower1(double px, double py, std::string s, int cst);
		~tower1(void);
		void draw(sf::RenderWindow &win);
		void fire();
		void check_collisions(mob &m);
	private:
		std::vector<Projectile1*>projectiles;
		std::vector<Projectile1*>::iterator it;
	};
}
