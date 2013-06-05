#pragma once
#include <SFML/Graphics.hpp>
#include "window.h"
namespace engine
{
	class game_engine
	{
	public:
		game_engine();
		~game_engine(void);
		void static start_game();
		void static go_to_menu();
		void static end_game();
		void manage_game();
	private:
		window * windowp;
		static int game_state;
	};
}

