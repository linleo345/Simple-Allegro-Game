//start of AllegroHeaders.h
#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "allegro5\allegro_primitives.h"
#include <allegro5\allegro_image.h>
#include <string>

#define DEBUG 1
#define _debug(message) if(DEBUG) std::cout << message << std::endl