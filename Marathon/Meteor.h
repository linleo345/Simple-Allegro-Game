
//start of Meteor.h
#pragma once
#include "Source.h"
#include "Man.h"

class Meteor {



public:
	void changeCoordsTo(int xCoord, int yCoord);
	
	void draw();
	void update();
	Meteor();
	~Meteor();

	int x;
	int y;
	int length = 14;

	bool meteorIntersects(Meteor *meteor, Man *man);
	bool xInRange(Meteor *meteor, Man *man);
	bool yNotIntercept(Meteor *meteor, Man *man);

private:


};