//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <GLFW/glfw3.h>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Set flags to work with opengl
		int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;

		//Create window
		window = SDL_CreateWindow("Testing Window Names", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			//screenSurface = SDL_GetWindowSurface( window );
			SDL_GL_CreateContext(window);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glBegin(GL_TRIANGLES);
			glColor4f(1, 1, 1, 1);
			glVertex3f(0.5, 0.5, 0.0);
			glVertex3f(-0.5, -0.5, 0.0);
			glVertex3f(0.5, -0.5, 0.0);
			glEnd();
			glFlush();

			//Update the surface
			SDL_GL_SwapWindow(window);

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}