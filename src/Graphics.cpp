#include "Graphics.h"
#include <iostream>

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;


int Graphics::windowWidth = 800;
int Graphics::windowHeight = 600;


bool Graphics::OpenWindow() {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		std::cerr << "SDL could not be initialized!" << "\n";
		return false;
	}

	window = SDL_CreateWindow("testApp", 500, 500, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if (!window) {

		std::cerr << "Window could not be created!" << "\n";
		return false;
	}

	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {

		std::cerr << "Renderer could not be created!" << "\n";
		return false;
	}

	return true;

}

void Graphics::RenderFrame()
{
	SDL_RenderPresent(renderer);
}

void Graphics::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void Graphics::CloseWindow(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


int Graphics::Width()
{
	return windowWidth;
}

int Graphics::Height()
{
	return windowHeight;
}
