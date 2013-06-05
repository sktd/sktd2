#pragma once
#include <SFML/Graphics.hpp>
#include "tower1.h"
#include "tower2.h"

namespace engine
{
	class player_console
	{
	public:
		player_console();
		~player_console(void);
		void subtract_life();
		void add_resources(int how_many);
		void subtract_resources(int how_many);
		void display(sf::RenderWindow &win);
	private:
		int lifes;
		int resources;
		map::tower1 tower1;
		map::tower2 tower2;
		map::tower1 tower3;
		sf::Text txt1;
		sf::Text txt2;
		sf::Text txt3;
		sf::Text lfs;
		sf::Text rscs;
		sf::Font font;
	};
}
