#include "Canvas.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "GameData.h"

const int Height_Of_Blocks = 20;
const int Width_Of_Blocks = 39;
const int Rows_Of_Blocks = 20;
const int Columns_Of_Blocks = 5;
const int Colour_Of_Blocks[5] = { EasyGraphics::DARK_RED, EasyGraphics::RED, EasyGraphics::DARK_YELLLOW, EasyGraphics::YELLOW, EasyGraphics::DARK_MAGENTA };
const int Screen_Width = 800;
const int Screen_Height = 600;
const int REDRAW_TIMER_ID = 1;

Canvas::Canvas() : gameStarted(false)
{
	setImmediateDrawMode(false);
	blocks = createBlocks();
	paddle = createPaddle();
	ball = createBall();
}

Canvas::~Canvas()
{
	delete paddle;
	delete ball;
	delete blocks;
}

void Canvas::onDraw() 
{
	if (!GameData::getGameData()->getGameOver())
	{
		clearScreen(WHITE);



		for_each(blocks->begin(), blocks->end(), [this](Block* block) {block->drawBlock(this); });
		ball->collision(blocks, paddle);
		paddle->drawPaddle(this);
		ball->drawBall(this);
		EasyGraphics::onDraw();
	}
}

void Canvas::onTimer(UINT nIDEvent)
{
	if (nIDEvent == REDRAW_TIMER_ID)
	{
		ball->movement();
		paddle->drawPaddle(this);
		onDraw();
	}
}



vector<Block*>* Canvas::createBlocks()
{
	/*RECT rect;
	GetClientRect(getHWND(), &rect);

	int elwidth = rect.right - rect.left / 20;
	int elheight = rect.bottom - rect.top / 50;*/

	int x = 0;
	int y = 0;

	vector<Block*>* gameBlocks = new vector<Block*>;

	for (int i = 0; i < Columns_Of_Blocks; i++)
	{
		for (int z = 0; z < Rows_Of_Blocks; z++)
		{
			Block* block = new Block(x, y, Width_Of_Blocks, Height_Of_Blocks, Colour_Of_Blocks[i], 1);
			gameBlocks->push_back(block);
			x += Width_Of_Blocks;
		}
		y += Height_Of_Blocks;
		x = 0;
	}

	return gameBlocks;
}

Paddle* Canvas::createPaddle()
{
	Paddle* paddle = new Paddle(300, 400, 120, 30);
	return paddle;
}

Ball* Canvas::createBall()
{
	Ball* ball = new Ball(360, 375, 20);
	return ball;
}

void Canvas::onMouseMove(UINT nFlags, int x, int y)
{
	paddle->movePaddle(x - paddle->getWidth() / 2);
	
}

void Canvas::onLButtonDown(UINT nFlags, int x, int y)
{
	if (!gameStarted)
	{
		gameStarted = true;
		ball->startDirection(45);
		SetTimer(getHWND(), REDRAW_TIMER_ID,1, NULL);
	}
}

