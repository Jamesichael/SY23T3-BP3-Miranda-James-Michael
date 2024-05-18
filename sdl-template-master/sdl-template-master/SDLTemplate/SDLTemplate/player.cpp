#include "player.h"
#include "draw.h"

void player::start()
{
	texture = loadTexture("gfx/player.png");

	x = 100;
	y = 330;
	width = 0;
	height = 0;
	speed = 2;
	speedUp = speed + 5;

	SDL_QueryTexture(texture, NULL, NULL, &width ,&height);

}

void player::update()
{

	if (app.keyboard[SDL_SCANCODE_W])
	{
		y -= speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		y += speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		y += speed;
	}


	if (app.keyboard[SDL_SCANCODE_A])
	{
		x -= speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		x += speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		x += speed;
	}


	if (app.keyboard[SDL_SCANCODE_S])
	{
		y += speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		y -= speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		y -= speed;
	}


	if (app.keyboard[SDL_SCANCODE_D])
	{
		x += speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		x -= speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		x -= speed;
	}
}

void player::draw()
{
	blit(texture, x, y);

}
