#include "player_console.h"
#include "game_engine.h"
#include <sstream>

engine::player_console::player_console():
	tower1(120, 510, "Grafika/tt.png", 40),
	tower2(170, 510, "Grafika/ballista.png", 20, 30 ,1),
	tower3(220, 510, "Grafika/catapult.png", 30)
{
	font.loadFromFile("Andale_Mono.ttf");
	std::ostringstream s;
	s<<tower1.get_cost();
	sf::Text tekst(s.str(), font, 30);
	tekst.setColor(sf::Color::White);
	tekst.setPosition(115,535);
	txt1=tekst;
	s.str("");

	s<<tower2.get_cost();
	sf::Text tekst2(s.str(), font, 30);
	tekst2.setColor(sf::Color::White);
	tekst2.setPosition(165,535);
	txt2=tekst2;
	s.str("");

	s<<tower3.get_cost();
	sf::Text tekst3(s.str(), font, 30);
	tekst3.setColor(sf::Color::White);
	tekst3.setPosition(215,535);
	txt3=tekst3;
	s.str("");

	lifes=10;
	lfs.setFont(font);
	lfs.setCharacterSize(50);
	lfs.setColor(sf::Color::White);
	lfs.setPosition(25, 500);

	resources=100;
	rscs.setFont(font);
	rscs.setCharacterSize(50);
	rscs.setColor(sf::Color::White);
	rscs.setPosition(270, 500);

}


engine::player_console::~player_console(void)
{
}

void engine::player_console::display(sf::RenderWindow &win)
{
	if(lifes<=0){
		engine::game_engine::go_to_menu();
		win.close();
	}

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

int engine::player_console::get_resources()
{
	return resources;
}

void engine::player_console::add_resources(int how_many)
{
	resources+=how_many;
}