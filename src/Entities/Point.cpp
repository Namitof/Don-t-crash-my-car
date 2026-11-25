#include "Point.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace DontCrashMyCar
{
	Point::Point()
	{
		pos.y = POINT_INITIAL_POS_Y;
		height = POINT_HEIGTH;
		width = POINT_WIDTH;
		speed = POINT_SPEED;
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
		pos.y = POINT_INITIAL_POS_Y;
		if (lane == 0)
		{
			pos.x = POINT_SPAWN_LANE_1;
		}
		else if (lane == 1)
		{
			pos.x = POINT_SPAWN_LANE_1 + POINT_LANE_OFFSET;
		}
		else if (lane == 2)
		{
			pos.x = POINT_SPAWN_LANE_1 + (POINT_LANE_OFFSET * 2);
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
}