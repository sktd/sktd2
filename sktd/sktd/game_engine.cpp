#include "game_engine.h"
#include "game_window.h"
#include "menu.h"

int engine::game_engine::game_state=1;

engine::game_engine::game_engine()
{
	//game_state=1;
}


engine::game_engine::~game_engine(void)
{
}

void engine::game_engine::start_game()
{
//	(*windowp).~window();
	game_state=2;
}

void engine::game_engine::end_game()
{
	//(*windowp).~window();
	game_state=0;
}

void engine::game_engine::go_to_menu()
{
//	(*windowp).~window();
	game_state=1;
}

void engine::game_engine::manage_game()
{
	while(game_state!=0)
	{
		switch(game_state){
		case 2:
			windowp=new engine::game_window(800, 600, 32, 1, "SKTD");
			break;
		case 1:
			windowp=new menu::menu(800, 600, 32, 3, "SKTD", 200, 150, 270, 390, "p1.png", "p1.png", "p2.png");
			break;
		}
		while((*windowp).isOpen()){
			windowp->handling_control();
		}
		delete windowp;
	}
}
