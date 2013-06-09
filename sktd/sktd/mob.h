#pragma once
#include "drawable.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
namespace map
{
	class mob :
		public ent::drawable
	{
	public:
		mob(double px, double py, std::string s, double vel, double hlth, int wrth, int destination);
		~mob(void);
		void move();
		void move(double x, double y);
		void reduce_health(double how_many);
		int get_destination();
		void set_destination(int d);
		bool is_ready();
		void start();
		bool collision(projectile &p);
		double get_health();
		int get_worth();
		void reduce_speed(double how_much);
		bool isReduced();
	/*	void check_collisions(tower &t);*/
	private:
		int destination;
		double health;
		int worth;
		bool ready;
		bool is_reduced;
		double velocity;
	};
}

