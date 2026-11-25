#include "Obstacle.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Obstacle::Obstacle()
{
	pos.y = -200;
	height = 150.0f;
	width = 150.0f;
	speed = 300;
	spawn();

	rect = sf::RectangleShape({ width, height });
}

Obstacle::~Obstacle()
{

}

sf::Vector2f Obstacle::getPos()
{
	return pos;
}

float Obstacle::getHeight()
{
	return height;
}

float Obstacle::getWidth()
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

	rect.setPosition(pos);

}

void Obstacle::draw(sf::RenderWindow& window)
{
	rect.setFillColor(sf::Color::Red);
	window.draw(rect);
}