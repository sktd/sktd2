#pragma once
#include <vector>
#include "mob.h"
#include "projectile.h"
#include "tower.h"
#include "tile.h"
#include "player_console.h"
#include <stdio.h>
#define MAP_NONE -1
#define MAP_ROAD 1
#define MAP_GRASS 2
#define MAP_BUILDABLE 3


namespace map
{
	class map
	{
	public:
		map(void);
		~map(void);
		void load_level(std::string filename);
		void begin_wave(double px, double py, std::string s, double vel, double hlth, int wrth, int hm);
		void end_wave();
		void build_tower(std::string s, double sp, int cst, engine::player_console &console, int which_tower);
		void display(sf::RenderWindow &win, engine::player_console &console);
		double get_start_x();
		double get_start_y();
		double get_end_x();
		double get_end_y();
		void move_chosen_r();
		void move_chosen_l();
		void set_direction(mob &m);
	private:
		const static int width=20;
		const static int height=8;
		double start_x;
		double start_y;
		double end_x;
		double end_y;
		std::vector <mob*> mobs;
		std::vector <tower*> towers;
		std::vector<mob*>::iterator itm;
		std::vector<tower*>::iterator itt;
		tile track[width*height];
		tile * chosen;
		int track2[801][601];
		sf::Clock clock;
		sf::Time time;
		sf::Int32 timeInt;
	};
}

