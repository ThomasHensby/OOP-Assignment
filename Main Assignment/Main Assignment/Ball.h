#pragma once
#include <string>
#include "EasyGraphics.h"
#include "Paddle.h"
#include "Block.h"

struct Velocity {

	double dX, dY;
	int speed = 4;
};

using namespace std;

class Ball
{

public:
	Ball(double x, double y, int radius);
	~Ball();
	void drawBall(EasyGraphics* window);
	double radianConverter(double radian);
	void collision(vector<Block*>*, Paddle* paddle);
	void movement();
	void startDirection(double angle);
	

private:
	int radius, angle;
	double x, y;
	static constexpr double PI = 3.141592653589793238;
	Velocity velocity;
};
 

inline void Ball::drawBall(EasyGraphics* window)
{
	window->setBackColour(window->BLUE);
	window->setPenColour(window->BLACK, 1);
	window->drawCircle(x, y, radius, true);
}

inline double Ball::radianConverter(double radian)
{
	const double conversion = (Ball::PI / 180);
	return radian * conversion;
}

inline void Ball::startDirection(double angle)
{
	velocity.dX = cos(radianConverter(angle));
	velocity.dY = sin(radianConverter(angle));
}