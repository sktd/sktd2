#pragma once
#include <string>
#include <SFML/Graphics.hpp>
namespace engine
{
	class window
	{
	public:
		window(int width, int height, int color_depth, int style, std::string title);
		~window(void);
		void virtual display()=0;
		void virtual handling_control()=0;
		bool isOpen();
	protected:
		sf::RenderWindow win;
	};
}

