//start of Man.cpp
#include "Man.h"
#include <iostream>



Man::Man()
{
	_debug("aMan loading.....");
	aMan = frame1 = al_load_bitmap("guy-Left0.png");
	_debug("aMan loaded");

	_debug("frame2 loading");
	frame2 = al_load_bitmap("guy-Left1.png");
	_debug("frame2 loaded");

	_debug("frame3 loading");
	frame3 = al_load_bitmap("guy-Left2.png");
	_debug("frame3 loaded");
	if (!aMan)
		std::cout << "Whoops" << std::endl;
	animation = 0;
	frames = 0;
	x = (SCREENWIDTH / 2) - 32;
	y = (SCREENHEIGHT / 2) - 64;
	
}


Man::~Man()
{

	al_destroy_bitmap(frame1);
	al_destroy_bitmap(frame2);
	al_destroy_bitmap(frame3);

}

void Man::draw()
{
	al_draw_bitmap(Man::aMan, x, y, NULL);

}

void Man::update()
{

	if (Man::moving && dir == 1)
		x -= 7;
	else if (Man::moving && dir == 2)
		x += 7;

	frames++;
	if (frames == 3)
	{
		if (moving == true)
		{
			if (animation == 0)
			{
				animation = 1;
			}
			else if (animation == 1)
			{
				aMan = frame2;
				animation = 2;

			}
			else if (animation == 2)
			{
				aMan = frame3;
				animation = 1;
			}

		}

		if (moving == false)
		{

			animation = 0;
			aMan = frame1;
		}

		frames = 0;
	}

}



void Man::setX(int toSetCoord)
{
	Man::x = toSetCoord;
}

void Man::setY(int toSetCoord)
{
	Man::y = toSetCoord;
}

int Man::getX()
{
	return Man::x;
}

int Man::getY()
{
	return Man::y;
}

int Man::getWidth()
{
	return Man::width;
}

int Man::getHeight()
{
	return Man::height;
}

bool Man::isDead()
{
	return Man::dead;
}

void Man::setDirection(int a) {
	dir = a;
}