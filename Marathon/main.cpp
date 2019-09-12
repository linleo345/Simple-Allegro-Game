#include "AllegroHeaders.h"
#include "Game.h"

#include <iostream>

int FPS()
{
	int fps;
	std::cout << "How fast would you like to run the game? (Recommended 30 - 35fps)" << std::endl;
	std::cin >> fps;
	return fps;
}



int main(void)
{
	
	
	srand(time(NULL));

	Game gamee;
	gamee.setFPS(FPS() * 1.3);
	gamee.go();
	gamee.cleanup();

	



	return 0;
}