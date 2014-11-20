#include "video.h"

#include <SDL.h>

SDL_Surface *screen;
int blinkTimer = 0;
int blinkTimerSlow = 0;

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
