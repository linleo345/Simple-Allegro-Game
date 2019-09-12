//start of Meteor.cpp

#include "Meteor.h"
#include <time.h>
#include <iostream>

Meteor::Meteor()
{
	x = rand() % SCREENWIDTH;
	y = -5000 - (rand() % 500);

}

Meteor::~Meteor()
{


}

void Meteor::changeCoordsTo(int xCoord, int yCoord)
{
	x = xCoord;
	y = yCoord;

}

void Meteor::draw()
{
	al_draw_line(x, y, x, y + length, al_map_rgb(128, 0, 0), 1);

}

void Meteor::update()
{
	y += 10;

	

	if (y > SCREENHEIGHT)
	{
		x = rand() % SCREENWIDTH;
		y = 0 - (rand() % 300);
	}

}



bool Meteor::xInRange(Meteor *meteor, Man *man) 
{
	if (meteor->x >= man->getX())
	{
		if (meteor->x <= man->getX() + man->getWidth())
			return true;
		return false;
	}

	return false;

}


bool Meteor::yNotIntercept(Meteor *meteor, Man *man) 
{
	bool above = meteor->y + meteor->length < man->getY();
	bool below = meteor->y > man->getY() + man->getHeight();

	if (above)
		return true;
	else if (below)
		return true;

	return false;

}

bool Meteor::meteorIntersects(Meteor *meteor, Man *man)
{
	bool xOk = xInRange(meteor, man);
	bool yNotInRange = yNotIntercept(meteor, man);

	if (xOk) {
		if (yNotInRange) {
			return false;
		}
		else  {
			return true;
		}
	}

	return false;
}