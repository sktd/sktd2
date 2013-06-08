#pragma once
#include "drawable.h"
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
	//	int get_id();
		bool is_ready();
		void start();
	private:
		int destination;
		double health;
		int worth;
	//	int id;
		bool ready;
		double velocity;
	};
}

