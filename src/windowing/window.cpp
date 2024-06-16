#include "window.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>


namespace windowing {

window::window(const std::string& title, int width, int height): m_width(width), m_height(height) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	constexpr SDL_WindowFlags flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	m_context = SDL_GL_CreateContext(m_window);

	glewExperimental = GL_TRUE;
	auto status = glewInit();
	if (status != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(status) << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	clear();
	SDL_GL_SwapWindow(m_window);
}

window::~window() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void window::clear() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}