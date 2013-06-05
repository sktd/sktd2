#include "window.h"

engine::window::window(int width, int height, int color_depth, int style, std::string title)
{
	win.create(sf::VideoMode(width, height, color_depth), title);
	win.clear(sf::Color::Black);
}


engine::window::~window(void)
{
	win.close();
}

bool engine::window::isOpen()
{
	if(win.isOpen())
		return true;
	else
		return false;
}