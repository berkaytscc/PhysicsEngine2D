#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <SDL.h>
#include "Physics/Vector2D.h"
#include <vector>
#include "Physics/Body.h"


struct Graphics
{
public:

	static int windowWidth;
	static int windowHeight;
	//static SDL_Renderer* renderer;
	//static SDL_Window* window;

	static bool OpenWindow();
	static void RenderFrame();
	static void ClearScreen();
	static void CloseWindow();

	static int Width();
	static int Height();

	static void DrawCircle(int x, int y, int radius, float angle, Uint32 color);
	static void DrawPolygon(std::vector<Vector2D> vertices); // SDL_Color color
	static void DrawBox(Body* body, int x, int y);
};



#endif


