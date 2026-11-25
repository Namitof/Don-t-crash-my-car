#include "Obstacle.h"
Obstacle::Obstacle()
{
	pos.y = -200;
	height = 150;
	width = 150;
	speed = 100;
	spawn();
}

Obstacle::~Obstacle()
{

}

sf::Vector2f Obstacle::getPos()
{
	return pos;
}

int Obstacle::getHeight()
{
	return height;
}

int Obstacle::getWidth()
{
	return width;
}

void Obstacle::spawn()
{
	lane = rand() % 3;
	pos.y = -200;
	if (lane == 0)
	{
		pos.x = 320;
	}
	else if (lane == 1)
	{
		pos.x = 320 + 255;
	}
	else if (lane == 2)
	{
		pos.x = 320 + 510;
	}
}

void Obstacle::move(float dt)
{
	if (pos.y < 720)
	{
		pos.y += speed * dt;
	}
	else
	{
		spawn();
	}
}