#pragma once
#include "drawable.h"
#include "mob.h"
#include <SFML/Graphics.hpp>
namespace map
{
	class tower :
		public ent::drawable
	{
	public:
		tower(double px, double py, std::string s, double spd, int cst);
		tower(double px, double py, std::string s, int cst);
		~tower(void);
		void virtual fire()=0;
		int get_cost();
		void virtual check_collisions(mob &m)=0;
	//	projectiles projectile;
	protected:
		/*std::vector<projectile*> projectiles;
		std::vector<projectile*>::iterator it;*/
		double pos_x;
		double pos_y;
		int cost;
		double speed;
		sf::Clock clock;
		sf::Time time;
		int timeInt;
	};
}
