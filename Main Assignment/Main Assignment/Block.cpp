#include "Block.h"


Block::Block(int x, int y, int width, int height, int colour, int health) : x(x), y(y), width(width), height(height), colour(colour), health(1)
{
	
}

Block::~Block()
{
}

bool Block::damageDelt()
{
	if (health == 1)
		this->health -= 1;
	return true;
}
