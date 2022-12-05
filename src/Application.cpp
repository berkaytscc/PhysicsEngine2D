#include "Application.h"
#include "Graphics.h"
#include "Physics/Constants.h"

bool Application::isRunning() {
	return running;
}

void Application::Setup() {
	running = Graphics::OpenWindow();
}

void Application::Input() {
	
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				running = false;
			if (event.key.keysym.sym == SDLK_d)
				debug = !debug;
			break;

		default:
			break;
		}
	}
}

void Application::Update() {
	
	Graphics::ClearScreen();
	static int timePreviousFrame;
	int timeToWait = DESIRED_DELTA - (SDL_GetTicks() - timePreviousFrame);

	if (timeToWait > 0)
		SDL_Delay(timeToWait);
}
void Application::Render() {
	Graphics::RenderFrame();
	//TODO: Render function is called several times per second to draw objects
}
/// <summary>
/// Call this method to delete objects in the scene
/// </summary>
void Application::Destroy() {
	Graphics::CloseWindow();
}