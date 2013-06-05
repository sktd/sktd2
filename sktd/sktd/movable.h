#pragma once
#include "drawable.h"
namespace ent
{
	class movable :
		public drawable
	{
	public:
		movable(double px, double py, std::string s, double vel);
		movable(void);
		~movable(void);
		bool collide(movable &a, movable &b);
		void move();
		void move(double x, double y);
		void draw(sf::RenderWindow &win);
	protected:
		double velocity;
	};
}

