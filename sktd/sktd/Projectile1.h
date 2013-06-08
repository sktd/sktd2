#pragma once
#include "projectile.h"
namespace map
{
	class Projectile1 :
		public projectile
	{
	public:
		Projectile1(double px, double py, std::string s, double vel, double dmg, double ang, int dest);
		~Projectile1(void);
		void draw(sf::RenderWindow &win);
	private:
		int destination;
	};
}
