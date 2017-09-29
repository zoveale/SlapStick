#include "..\inculde\Window.h"



Window::Window()
{
	window = nullptr;
	mainRenderer = nullptr;
}

void Window::Initialize()
{
	window = SDL_CreateWindow("SlapStick", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) SDL_GetError(); 
	mainRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (mainRenderer = nullptr) SDL_GetError();

}

void Window::Draw()
{
	//Clear screen
	SDL_RenderClear(mainRenderer);

	//Render texture to screen
	SDL_RenderCopy(mainRenderer, nullptr , NULL, NULL);

	//Update screen
	SDL_RenderPresent(mainRenderer);
	SDL_Delay(1000);
}

void Window::Update()
{
}


Window::~Window()
{
}
