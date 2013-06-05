#pragma once
#include "tower.h"
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
	private:
		double rotation;
	};
}
