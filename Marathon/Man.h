//start of Man.h

#pragma once

#include "Source.h"


class Man
{
	

public:

	Man();
	~Man();

	void init();

	void draw();
	void update();

	void setMoving(bool stateMoving) {  moving = stateMoving;  }
	bool isPlayerMoving() { return moving;  }

	void setX(int toSetCoord);
	void setY(int toSetCoord);

	int getX();
	int getY();

	int getWidth();
	int getHeight();

	bool isDead();

	bool dead = false;

	void setDirection(int a);
	

private:
	bool moving;
	ALLEGRO_BITMAP* aMan, *frame1, *frame2, *frame3;
	int animation;
	int frames;
	int x = 0, y = 0;
	const int width = 32;
	const int height = 64;

	int dir = 1;


	
protected:




};