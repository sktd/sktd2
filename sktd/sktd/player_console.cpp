#include "player_console.h"
#include <sstream>

engine::player_console::player_console():
	tower1(100, 500, "t1.png", 10),
	tower2(150, 500, "t2.png", 20),
	tower3(200, 500, "t3.png", 30)
{
	font.loadFromFile("Andale_Mono.ttf");
	std::ostringstream s;
	s<<tower1.get_cost();
	sf::Text tekst(s.str(), font, 30);
	tekst.setColor(sf::Color::White);
	tekst.setPosition(100,525);
	txt1=tekst;
	s.str("");

	s<<tower2.get_cost();
	sf::Text tekst2(s.str(), font, 30);
	tekst2.setColor(sf::Color::White);
	tekst2.setPosition(150,525);
	txt2=tekst2;
	s.str("");

	s<<tower3.get_cost();
	sf::Text tekst3(s.str(), font, 30);
	tekst3.setColor(sf::Color::White);
	tekst3.setPosition(200,525);
	txt3=tekst3;
	s.str("");

	lifes=10;
	lfs.setFont(font);
	lfs.setCharacterSize(50);
	lfs.setColor(sf::Color::White);
	lfs.setPosition(20, 500);

	resources=1000;
	rscs.setFont(font);
	rscs.setCharacterSize(50);
	rscs.setColor(sf::Color::White);
	rscs.setPosition(300, 500);

}


engine::player_console::~player_console(void)
{
}

void engine::player_console::display(sf::RenderWindow &win)
{
	std::ostringstream s;
	s<<lifes;
	lfs.setString(s.str());
	s.str("");
	s<<resources;
	rscs.setString(s.str());
	tower1.draw(win);
	tower2.draw(win);
	tower3.draw(win);
	win.draw(txt1);
	win.draw(txt2);
	win.draw(txt3);
	win.draw(lfs);
	win.draw(rscs);
}

void engine::player_console::subtract_life()
{
	lifes--;
}

void engine::player_console::subtract_resources(int how_many)
{
	resources-=how_many;
}