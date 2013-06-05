#pragma once
#include "drawable.h"
#include <SFML/Graphics.hpp>
namespace map
{
	class projectile :
		public ent::drawable
	{
	public:
		projectile(double px, double py, std::string s, double vel, double dmg, double ang);
		~projectile(void);
		void move(double x, double y);
		double get_scale();
		void set_scale(double scale);
	private:
		double damage;
		double angle;
		double velocity;
	//	double scale;
	};
}

