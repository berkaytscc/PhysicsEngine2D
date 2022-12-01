#include "Application.h"

bool Application::isRunning() {
	return running;
}

void Application::Setup() {
	//TODO: Open window --> OpenWindow()
	//		setup objects in the scene
}

void Application::Input() {
	//TODO: Input processing
}

void Application::Update() {
	//TODO: Update all objects in the scene
}
void Application::Render() {
	//TODO: Render function is called several times per second to draw objects
}
/// <summary>
/// Call this method to delete objects in the scene
/// </summary>
void Application::Destroy() {
	//TODO: Delete objects and close the window
	//		Close window --> CloseWindow()
}