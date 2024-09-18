#include <SDL2/SDL.h>

#include <string>

namespace windowing {

class window {
private:
	SDL_Window* m_window;
	SDL_GLContext m_context;

	int m_width, m_height;

public:
	window(const std::string& title, int width, int height);
	~window();

	void clear();
};

}
