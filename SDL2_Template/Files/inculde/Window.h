#ifndef WINDOW_H
#define WINDOW_H


#include "System.h"

class Window : public System
{
private:
	SDL_Window* window;
	SDL_Renderer* mainRenderer;
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 740;

public:
	Window();

	void Initialize();
	void Draw();
	void Update();

	~Window();
};

#endif // !1