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
		void move(int destination);
		double get_damage();
		virtual void draw(sf::RenderWindow &win)=0;
	protected:
		double damage;
		double angle;
		double velocity;
	//	double scale;
	};
}

