#include "Point.h"


Point::Point()
{
	pos.y = -200;
	height = 150;
	width = 150;
	speed = 100;
	spawn();
}

Point::~Point()
{

}

sf::Vector2f Point::getPos()
{
	return pos;
}

int Point::getHeight()
{
	return height;
}

int Point::getWidth()
{
	return width;
}

void Point::spawn()
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

void Point::move(float dt)
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