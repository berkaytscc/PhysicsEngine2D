#include "Application.h"

bool Application::isRunning() {
	return running;
}

void Application::Setup() {
	running = Graphics::OpenWindow();

	// create world
	world = new World(-9.8f);
	
	BoxShape boxShape = BoxShape(140, 140);
	Vector2D v = Vector2D(200, 200);
	Vector2D v2 = Vector2D(200, 400);
	Vector2D v3 = Vector2D(100, 400);
	Vector2D v4 = Vector2D(200, 200);
	
	Body* box = new Body(boxShape, Graphics::Width() / 2.0, Graphics::Height() / 2.0, 0.0);
	
	box->shape->worldVertices.push_back(v);
	box->shape->worldVertices.push_back(v2);
	box->shape->worldVertices.push_back(v3);
	box->shape->worldVertices.push_back(v4);

	world->AddBody(box);
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
	//TODO: Render function is called several times per second to draw objects
	for (auto body: world->GetBodies())
	{
		if (body->shape->GetType() == BOX)
		{
			Graphics::DrawPolygon(500, 500, body->shape->worldVertices);
		}
	}
	Graphics::RenderFrame();
}
/// <summary>
/// Call this method to delete objects in the scene
/// </summary>
void Application::Destroy() {
	Graphics::CloseWindow();
}