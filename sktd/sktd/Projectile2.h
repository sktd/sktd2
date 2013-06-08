#pragma once
#include "projectile.h"
namespace map
{
	class Projectile2 :
		public projectile
	{
	public:
		Projectile2(double px, double py, std::string s, double vel, double dmg, double ang);
		~Projectile2(void);
		void draw(sf::RenderWindow &win);
		double get_scale();
		void set_scale(double scale);
	private:

	};
}
