#include "menu.h"
#include "mob.h"
#include "game_window.h"
#include "game_engine.h"
#include <vector>
#include <string>
int main()
{
//	engine::game_window gw(800, 600, 32, 1, "SKTD");
	engine::game_engine engine;
	//engine.window=new menu::menu(800, 600, 32, 3, "SKTD", 200, 150, 270, 390, "p1.png", "p1.png", "p1.png");
	engine.manage_game();
	

	//sf::Image im;
	//im.loadFromFile("pocisk_kolowy.bmp");
	//im.createMaskFromColor(sf::Color::Black);
	//im.saveToFile("pocisk_kolowy.png");


    return 0;
}