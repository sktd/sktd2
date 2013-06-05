#pragma once
#include "tower.h"
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
	};
}
