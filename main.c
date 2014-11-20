#include "main.h"

#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "fileio.h"
#include "input.h"
#include "states.h"
#include "video.h"

int quit;

int init()
{
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK))
	{
		return -1;
	}

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(screen == NULL)
	{
		return -1;
	}

	if(SDL_NumJoysticks() > 0)
	{
		SDL_JoystickOpen(0);
	}

	return 0;
}

int deinit()
{
	if(SDL_NumJoysticks() > 0)
	{
		SDL_JoystickClose(0);
	}

	SDL_Quit();

	if(configDir)
	{
		free(configDir);
	}

	return 0;
}

int main()
{
	quit = 0;

	getConfigDir();
	getConfig();

	if(init())
	{
		quit = 1;
	}

	srand(time(NULL));

	while(!quit)
	{
#if defined(DEBUG)
		SDL_Delay(1);
#endif
		input();
		logic();
		draw();
	}

	storeConfig();
	deinit();

	return 0;
}
