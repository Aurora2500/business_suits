#include "game.hpp"

#include <SDL2/SDL.h>

#include <iostream>

#include "windowing/window.hpp"

void run_game() {
	windowing::window window("Business Suits", 800, 600);

	SDL_Event event;
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
	}
}