#pragma once
#include "mob.h"
namespace map
{
	class mob1 :
		public mob
	{
	public:
		mob1(double px, double py, std::string s, double vel, double hlth, int wrth, int destination);
		~mob1(void);
	};
}

