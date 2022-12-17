#include "Application.h"

bool Application::isRunning() {
	return running;
}

void Application::Setup() {
	running = Graphics::OpenWindow();

	// create world
	world = new World(-9.8f);

	Vector2D v0 = Vector2D(100, 100);
	Vector2D v1 = Vector2D(300, 100);
	Vector2D v2 = Vector2D(250, 250);
	Vector2D v3 = Vector2D(100, 250);

	PolygonShape polygonShape = PolygonShape();

	Body* polygon = new Body(polygonShape, 0.0f, 0.0f, 0.0f);
	
	polygon->shape->worldVertices.push_back(v0);
	polygon->shape->worldVertices.push_back(v1);
	polygon->shape->worldVertices.push_back(v2);
	polygon->shape->worldVertices.push_back(v3);

	world->AddBody(polygon); //why box is rendering but polygon not?




	BoxShape boxShape = BoxShape(100, 100);
	Body* box = new Body(boxShape, 0.0f, 0.0f, 0.0f);
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
			if (event.key.keysym.sym == SDLK_ESCAPE) // Close the app when clicked esc
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
			Graphics::DrawBox(body, 100, 300);
		}

		if (body->shape->GetType() == POLYGON) {
			Graphics::DrawPolygon(body->shape->worldVertices);
		}
		if (body->shape->GetType() == CIRCLE) {
			//DrawCircle
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