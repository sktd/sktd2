#include "game_window.h"
#include "game_engine.h"

engine::game_window::game_window(int w, int h, int cd, int style, std::string t):
	window(w, h, cd, style, t)
{
	next_wave=1;
}


engine::game_window::~game_window(void)
{
}

void engine::game_window::display()
{
	win.clear(sf::Color::Black);
	map1.display(win, console);
	console.display(win);
	win.display();
}

void engine::game_window::handling_control()
{
	//while(win.isOpen()){
		sf::Event ev;
		while( win.pollEvent( ev ) )
		{
			if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape ){
				win.close();
				engine::game_engine::go_to_menu();
			}
		
			if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Num1 )
				map1.build_tower("t1.png",100,10, console, 1);
			
			if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Num2 )
				map1.build_tower("t2.png",100,20, console, 2);
			
			if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Num3 )
				map1.build_tower("t3.png",100,30, console, 1);
		
			if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Right )
				map1.move_chosen_r();
			
			if( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Left )
				map1.move_chosen_l();
				
		
		}
		time=clock.getElapsedTime();
		timeInt=time.asSeconds();
		if(timeInt==2&&next_wave==1){
			map1.begin_wave(map1.get_start_x(), map1.get_start_y(), "pacman.png", 0.1, 2,2,3);
			next_wave++;
		}
			
		display();
//	}

}