#pragma once
#include "EasyGraphics.h"
#include "Block.h"
#include "Paddle.h"
#include "Ball.h"


class Canvas : public EasyGraphics
{
public:
	Canvas();
	~Canvas();

	virtual void onDraw();
	virtual void onTimer(UINT nIDEvent);
	vector<Block*>* createBlocks();
	Paddle* createPaddle();
	Ball* createBall();
	virtual void onMouseMove(UINT nFlags, int x, int y);
	virtual void onLButtonDown(UINT nFlags, int x, int y);
	void close();

private:
	vector<Block*>* blocks;
	Paddle* paddle;
	Ball* ball;
	bool gameStarted;

};

inline void Canvas::close()
{
	SendMessage(getHWND(), WM_CLOSE, 0, 0);
}
