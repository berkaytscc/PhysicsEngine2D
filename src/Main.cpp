#include "Application.h"
#include "Graphics.h"

int main(int argc, char* args[])
{
	Application app;
	
	app.Setup();

	while (app.isRunning())
	{
		app.Input();
		app.Update();
		app.Render();
	}

	app.Destroy();

	return 0;
}
