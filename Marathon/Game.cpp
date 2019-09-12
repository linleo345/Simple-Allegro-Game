//start of Game.cpp

#include "Game.h"
#include "AllegroHeaders.h"
#include <iostream>


ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *allegro_timer;
ALLEGRO_FONT *font;
ALLEGRO_BITMAP *ending;

int Game::setFPS(int gamefps)
{
	FPS = gamefps;
	return  (1 / gamefps);
}

int Game::currentFPS()
{		
	return FPS;
}

void Game::setScore(int gameScore)
{
	score = gameScore;
}

int Game::getScore()
{
	return score;
}


void Game::go()
{
	al_init();

	_debug("keyboard initializing");
	al_install_keyboard();
	_debug("keyboard initialized");

	_debug("image initializing");
	al_init_image_addon();
	_debug("image initialized");

	_debug("font initializing");
	al_init_font_addon();
	_debug("font initialized");


	_debug("ttf initializing");
	al_init_ttf_addon();
	_debug("ttf initialized");

	_debug("primitives initialized");
	al_init_primitives_addon();
	_debug("primitives initialized");

	queue = al_create_event_queue();

	display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
	allegro_timer = al_create_timer((double)((double)1.0 / FPS));

	al_register_event_source(queue, al_get_timer_event_source(allegro_timer));
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_start_timer(allegro_timer);

	dude = new Man();

	for (int i = 0; i < 30; i++)
		meteors[i] = new Meteor();



	dude->setX(SCREENWIDTH - dude->getWidth());
	dude->setY(SCREENHEIGHT - dude->getHeight());


	_debug("Loading arial");
	font = al_load_ttf_font("arial.ttf", 12, 0);
	_debug("Loaded arial");
	if (!font)
		std::cout << "couldnt load";
		
	_debug("Loading ending");
	ending = al_load_bitmap("ending.png");


	this->intro();

	ALLEGRO_EVENT event1;
	

	bool scared = false;
	bool endSong = false;

	while (!done)
	{
		al_wait_for_event(queue, &event1);
		if (!dude->isDead())
		{
			if (event1.type == ALLEGRO_EVENT_TIMER)
			{
				if (!dude->isDead())
					setScore(getScore() + 1);

				
				redraw = true; 
				dude->update();
				for (int i = 0; i < 30; i++) {
					meteors[i]->update();
					dude->dead |= meteors[i]->meteorIntersects(meteors[i], dude);
				}

			}

			if (redraw && al_event_queue_is_empty(queue))
			{

				al_clear_to_color(al_map_rgb(255, 255, 255));
				dude->draw();

				for (int i = 0; i < 30; i++)
					meteors[i]->draw();
				

				al_draw_text(font, al_map_rgb(8, 253, 0), 100, 20, ALLEGRO_ALIGN_CENTRE, "Score:");
				al_draw_textf(font, al_map_rgb(8, 253, 0), 110, 40, ALLEGRO_ALIGN_CENTRE, "%i", this->getScore());

				al_flip_display();
				redraw = false; 
			}
		}
			

			if (event1.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				if (event1.keyboard.keycode == ALLEGRO_KEY_LEFT)
				{
					dude->setMoving(true);
					dude->setDirection(1);
				}
				if (event1.keyboard.keycode == ALLEGRO_KEY_RIGHT)
				{
					dude->setMoving(true);
					dude->setDirection(2);
				}

			}

			if (event1.type == ALLEGRO_EVENT_KEY_UP)
			{
				if (event1.keyboard.keycode == ALLEGRO_KEY_RIGHT || event1.keyboard.keycode == ALLEGRO_KEY_LEFT)
				{
					dude->setMoving(false);
				}

			}


		else if (dude->isDead())
		{

			al_clear_to_color(al_map_rgb(0, 0, 0));

			if (!scared)
			{
				al_draw_bitmap(ending, 0, 0, 0);
				al_flip_display();
				al_rest(2.0);
				scared = true;
			}
			if (!endSong)
			{
				
				endSong = true;
			}

			al_draw_textf(font, al_map_rgb(255, 255, 255), 60, 220, 0,"Thank you for watching! ( Final score was: %i )", this->getScore());
			al_draw_text(font, al_map_rgb(255, 255, 255), 150, 240, 0, "-Leo");
			al_flip_display();
			
			
		}

		if (event1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

	}

}

Game::Game()
{

	Game::setScore(0);
}

Game::~Game()
{

	delete dude;
	for (int i = 20; i < 20; i++)
	{
		delete meteors[i];
	}
}


void Game::cleanup()
{
	al_destroy_display(display);
	al_destroy_event_queue(queue);
	al_destroy_timer(allegro_timer);
	al_destroy_font(font);
	al_destroy_bitmap(ending);

}

void Game::intro()
{
	font = al_load_ttf_font("Arial.ttf", 12, 0);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREENWIDTH / 4, (SCREENHEIGHT / 2), 0, "This game was developed by Leo Lin and");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREENWIDTH / 4, (SCREENHEIGHT / 2) + 30, 0, "used Allegro 5.0.10 gaming library.");
	al_flip_display();

	al_rest(5.0);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREENWIDTH / 4, (SCREENHEIGHT / 2), 0, "Use Left and Right arrow keys to dodge falling spikes as long as ");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREENWIDTH / 4, (SCREENHEIGHT / 2)+ 30, 0, "possible!");
	al_flip_display();

	al_rest(7.0);

}




