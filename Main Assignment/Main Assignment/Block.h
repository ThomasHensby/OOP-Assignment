#pragma once
#include <string>
#include "EasyGraphics.h"

class Block
{
public:
	Block(int x, int y, int width, int height, int colour, int health);
	~Block();
	void drawBlock(EasyGraphics* window);
	bool damageDelt();
	int getX();
	int getY();
	int getWidth();
	int getHeight();


private:
	int health, colour, x, y, width, height;
	const int Colour_Of_Blocks[5] = { EasyGraphics::DARK_RED, EasyGraphics::RED, EasyGraphics::DARK_YELLLOW, EasyGraphics::YELLOW, EasyGraphics::DARK_MAGENTA };

};



inline void Block::drawBlock(EasyGraphics* window) //get rid of a cyclic refrence
{
	window->setBackColour(colour);
	window->setPenColour(window->BLACK, 1);
	window->drawRectangle(x, y, width, height, true);
}



inline int Block::getX()
{
	return x;
}

inline int Block::getY()
{
	return y;
}

inline int Block::getWidth()
{
	return width;
}

inline int Block::getHeight()
{
	return height;
}

