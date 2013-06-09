#pragma once
#include "window.h"
#include "player_console.h"
#include "map.h"
#include <SFML/Graphics.hpp>
namespace engine
{
	class game_window :
		public window
	{
	public:
		game_window(int w, int h, int cd, int style, std::string t);
		~game_window(void);
		void display();
		void handling_control();
	private:
		sf::Clock clock;
		sf::Time time;
		sf::Int64 timeInt;
		sf::Texture background;
		sf::Sprite bg;
		map::map map1;
		player_console console;
		int next_wave;
	};
}

