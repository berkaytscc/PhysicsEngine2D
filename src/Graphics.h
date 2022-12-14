#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <SDL.h>
#include "Physics/Vector2D.h"
#include <vector>


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

	static void DrawPolygon(int x, int y, std::vector<Vector2D> vertices); // SDL_Color color
};



#endif


