#include "video.h"

#include <SDL.h>

SDL_Surface *screen;
Uint32 curTicks;
Uint32 lastTicks = 0;
int blinkTimer = 0;
int blinkTimerSlow = 0;

int frameLimiter()
{
	int t;

#if defined(NO_FRAMELIMIT)
	return 0;
#endif

	curTicks = SDL_GetTicks();
	t = curTicks - lastTicks;

	if(t >= 1000/FPS)
	{
		lastTicks = curTicks;
		return 0;
	}

	SDL_Delay(1);
	return 1;
}

void blinkTimersTick()
{
	if(++blinkTimer > 20)
	{
		blinkTimer = 0;
	}
	if(++blinkTimerSlow > 40)
	{
		blinkTimerSlow = 0;
	}
}

void clearScreen()
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
}
