#include "Ball.h"
#include "GameData.h"


Ball::Ball(double x, double y, int radius) : x(x), y(y), radius(radius)
{
	
}

Ball::~Ball()
{
}



void Ball::movement()
{
	x += (velocity.dX * velocity.speed);
	y -= (velocity.dY * velocity.speed);
}

void Ball::collision(vector<Block*>* blocks, Paddle* paddle)
{
	//collision check on walls
	if (x <= 0 + radius || x >= 800 - radius * 2 ) {
		velocity.dX = -velocity.dX;
	}
	if (y <= 0 + radius) {
		velocity.dY = -velocity.dY;
	}
	if (y >= 600 + radius) {
		GameData::getGameData()->setGameOver(true);
	}
	
	//collision check on blocks
	for (int i = 0; i < blocks->size(); i++) {
		if((x + radius > blocks->at(i)->getX() && x - radius < blocks->at(i)->getX() + blocks->at(i)->getWidth()) && y < blocks->at(i)->getY() + blocks->at(i)->getHeight() && y > blocks->at(i)->getY())
		{ 
			velocity.dX = -velocity.dX;
			if (blocks->at(i)->damageDelt() == true)
			{
				delete blocks->at(i);
				//blocks->erase(blocks->begin() + i);
			}
		}
		else if ((y + radius > blocks->at(i)->getY() && y - radius < blocks->at(i)->getY() + blocks->at(i)->getHeight()) && x < blocks->at(i)->getX() + blocks->at(i)->getWidth() && x > blocks->at(i)->getX())
		{
			velocity.dY = -velocity.dY;
			if (blocks->at(i)->damageDelt() == true)
			{
				delete blocks->at(i);
				//blocks->erase(blocks->begin() + i);
			}
		}
	
	}


	//collsion check on paddle
	if (y + radius > paddle->getY() && y - radius < paddle->getY() + paddle->getWidth() && x < paddle->getX() + paddle->getWidth() && x > paddle->getX())
	{
		velocity.dY = -velocity.dY;
	}


	
	
}

