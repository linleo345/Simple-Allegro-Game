//start of Game.h
#pragma once

#include "Source.h"
#include "Man.h"
#include "Meteor.h"


extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *queue;
extern ALLEGRO_TIMER *al_timer;
extern ALLEGRO_FONT *font;
extern ALLEGRO_BITMAP *ending;






class Game
{
	
public:

	Game();
	~Game();

	void go();

	void setScore(int gameScore);

	int setFPS(int gameFps);

	int currentFPS();
	int getScore();
	
	void cleanup();

	void intro();
		

private:
	Man *dude; 
	Meteor *meteors[40];


	unsigned long int score;
	unsigned int FPS; 

	bool redraw;
	bool  done;

};

