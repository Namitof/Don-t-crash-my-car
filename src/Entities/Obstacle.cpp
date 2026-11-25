#include "Obstacle.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace DontCrashMyCar
{
	Obstacle::Obstacle()
	{
		pos.y = OBSTACLE_INITIAL_POS_Y;
		height = OBSTACLE_HEIGHT;
		width = OBSTACLE_WDITH;
		speed = OBSTACLE_SPEED;
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
		pos.y = OBSTACLE_INITIAL_POS_Y;
		if (lane == 0)
		{
			pos.x = OBSTACLE_SPAWN_LANE_1;
		}
		else if (lane == 1)
		{
			pos.x = OBSTACLE_SPAWN_LANE_1 + OBSTACLE_LANE_OFFSET;
		}
		else if (lane == 2)
		{
			pos.x = OBSTACLE_SPAWN_LANE_1 + (OBSTACLE_LANE_OFFSET * 2);
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
}