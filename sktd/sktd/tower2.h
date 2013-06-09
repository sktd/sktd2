#pragma once
#include "tower.h"
#include "Projectile2.h"
//#include "player_console.h"
//#include "mob.h"
namespace map
{
	class tower2 :
		public tower
	{
	public:
		tower2(double px, double py, std::string s, double spd, int cst, double rotation);
		tower2(double px, double py, std::string s, int cst);
		~tower2(void);
		void fire();
		void draw(sf::RenderWindow &win);
		void check_collisions(mob &m);
	private:
		std::vector<Projectile2*>projectiles;
		std::vector<Projectile2*>::iterator it;
		double rotation;
	};
}

