#pragma once
#include "drawable.h"
namespace ent
{
	class immovable :
		public drawable
	{
	public:
		immovable(double px, double py, std::string s);
		immovable();
		~immovable(void);
	};
}

