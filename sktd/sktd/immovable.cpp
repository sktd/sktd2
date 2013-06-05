#include "immovable.h"


ent::immovable::immovable(double px, double py, std::string s)
{
	t.loadFromFile(s);
	sp.setTexture(t);
	sp.setPosition(px,py);
}


ent::immovable::~immovable(void)
{
}

ent::immovable::immovable()
{
}