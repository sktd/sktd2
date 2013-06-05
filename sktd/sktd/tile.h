#pragma once
#include "drawable.h"
#include <SFML/Graphics.hpp>
namespace map
{
	class tile :
		public ent::drawable
	{
	public:
		tile(double px, double py, std::string s, int tp);
		tile();
		~tile(void);
		void draw(sf::RenderWindow &win);
		void draw2(sf::RenderWindow &win);
		int get_type();
		void set_type(int t);
	private:
		int type;
	};
}
