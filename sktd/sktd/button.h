#pragma once
#include "drawable.h"
#include <SFML\Graphics.hpp>
namespace menu
{
	class button :
		public ent::drawable
	{
	public:
		button(double px, double py, std::string s);
		~button(void);
		void draw(sf::RenderWindow &win);
		void draw2(sf::RenderWindow &win);
		void push();
	};
}
