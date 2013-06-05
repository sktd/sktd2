#pragma once
#include "drawable.h"
#include "projectile.h"
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
	//	projectiles projectile;
	protected:
		std::vector<projectile*> projectiles;
		std::vector<projectile*>::iterator itp;
		double pos_x;
		double pos_y;
		int cost;
		double speed;
		sf::Clock clock;
	};
}
