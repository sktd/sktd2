#pragma once
#include "tower.h"
#include "Projectile1.h"
namespace map
{
	class Tower3 :
		public tower
	{
	public:
		Tower3(double px, double py, std::string s, double spd, int cst);
		Tower3(double px, double py, std::string s, int cst);
		~Tower3(void);
		void draw(sf::RenderWindow &win);
		void fire();
		void check_collisions(mob &m);
	private:
		std::vector<Projectile1*>projectiles;
		std::vector<Projectile1*>::iterator it;
	};
}

