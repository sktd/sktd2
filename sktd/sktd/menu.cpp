#include "menu.h"
#include "game_engine.h"


menu::menu::menu(int w, int h, int cd, int style, std::string t, double px, double py1, double py2, double py3, std::string s1, std::string s2, std::string s3):
	window(w, h, cd, style, t),
	new_game(px, py1, s1),
	continue_game(px, py2, s2),
	end_game(px, py3, s3)
{
	choice=1;
	chosen=&new_game;
	font.loadFromFile("Andale_Mono.ttf");
	title.setFont(font);
	title.setCharacterSize(60);
	title.setColor(sf::Color::White);
	title.setString("SK Tower Defense");
	title.setPosition(140,10);
}


menu::menu::~menu(void)
{
}

void menu::menu::display(){
	win.clear(sf::Color::Black);
	new_game.draw(win);
	continue_game.draw(win);
	end_game.draw(win);
	win.draw(title);
	(*chosen).draw2(win);
	win.display();
}

void menu::menu::handling_control()
{
	sf::Event ev;
	while( win.pollEvent( ev ) )
	{

		if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Down )
			if(choice!=3)
				choice++;
			else
				choice=1;
			
		if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Up )
			if(choice!=1)
				choice--;
			else
				choice=3;
		
		if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Return ){
			switch(choice){
			case 1:
				engine::game_engine::start_game();
				win.close();
				break;
			case 2:
				engine::game_engine::end_game();
				win.close();
				break;
			case 3:
				engine::game_engine::end_game();
				win.close();
				break;
			}
		}
		
		switch(choice){
		case 1:
			chosen=&new_game;
			break;
		case 2:
			chosen=&continue_game;
			break;
		case 3:
			chosen=&end_game;
			break;
		}
	}
	display();
}
