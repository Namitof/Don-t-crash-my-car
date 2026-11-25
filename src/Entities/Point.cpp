#include "Point.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Point::Point()
{
	pos.y = -200;
	height = 150.0f;
	width = 150.0f;
	speed = 300;
	spawn();

	rect = sf::RectangleShape({ width, height });
}

Point::~Point()
{

}

sf::Vector2f Point::getPos()
{
	return pos;
}

float Point::getHeight()
{
	return height;
}

float Point::getWidth()
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

	rect.setPosition(pos);
}

void Point::draw(sf::RenderWindow& window)
{
	rect.setFillColor(sf::Color::Green);
	window.draw(rect);
}