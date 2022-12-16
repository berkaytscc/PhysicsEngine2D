#ifndef APPLICATION_H
#define APPLICATION_H

#include "Physics/World.h"
#include "Graphics.h"
#include "Physics/Constants.h"
class Application
{
private: 
	bool debug = false; // Unclear, learn how to use it
	bool running = false;
	World* world;

public:
	Application() = default;
	~Application() = default;
	bool isRunning();
	void Setup();
	void Input();
	void Update();
	void Render();
	void Destroy();

};

#endif // APPLICATION_H


