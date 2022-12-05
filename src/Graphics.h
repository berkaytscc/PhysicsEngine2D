#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <SDL.h>



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

};



#endif


