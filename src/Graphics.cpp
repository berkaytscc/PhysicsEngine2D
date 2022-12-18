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

void Graphics::DrawCircle(int x, int y, int radius)
{
	int x_temp = 0;
	int y_temp = 0;
	int x_0, y_0;
	// lineColor(renderer, x, y, x + cos(angle) * radius, y + sin(angle) * radius, color);
	for (int i = 0; i < 36; i++) {
		float radians = i * M_PI / 18;

		x_0 = x + radius * cos(radians);
		y_0 = y + radius * sin(radians);
		
		if (i == 0) { SDL_RenderDrawPoint(renderer, x_0, y_0); }
		else {
			SDL_RenderDrawLine(renderer, x_temp, y_temp, x_0, y_0);
		}

		x_temp = x_0;
		y_temp = y_0;
		SDL_RenderDrawPoint(renderer, x_0, y_0);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}


}

void Graphics::DrawPolygon(std::vector<Vector2D> vertices)
{
	//TODO: SDL_Color paramater will be added

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red

	for (int i = 0; i < vertices.size(); i++)
	{
		int currentIndex = i;						// 0 1 2 3
		int nextIndex = (i + 1) % vertices.size();	// 1 2 3 0

		SDL_RenderDrawLine(renderer, (int)vertices[currentIndex].x, (int)vertices[currentIndex].y,
										(int)vertices[nextIndex].x, (int)vertices[nextIndex].y);
	}
}

void Graphics::DrawBox(Body* body, int x, int y)
{

	SDL_SetRenderDrawColor(renderer, 56, 152, 122, 255);

	SDL_Rect rect;

	BoxShape* box = (BoxShape*)body->shape;

	rect.x = x;
	rect.y = y;
	rect.w = box->width;
	rect.h = box->height;

	SDL_RenderDrawRect(renderer, &rect);
}
