#include "Lane.h"

Lane::Lane(sf::Vector2f pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	width = 1280;
	height = 720;
	speed = 100;
}

Lane::~Lane()
{

}

void Lane::spawn()
{
	pos.x = 0;
	pos.y = 0;
}

void Lane::move(float dt)
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

void Lane::draw()
{

}
