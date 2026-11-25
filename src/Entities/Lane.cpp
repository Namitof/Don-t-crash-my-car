#include "Lane.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace DontCrashMyCar
{
	Lane::Lane(sf::Vector2f pos)
	{
		this->pos.x = pos.x;
		this->pos.y = pos.y;
		width = 1280.0f;
		height = 720.0f;
		speed = LANE_SPEED;

		rect = sf::RectangleShape({ width, height });
	}

	Lane::~Lane()
	{

	}

	void Lane::spawn()
	{
		pos.x = 0;
		pos.y = -720.0f;
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

		rect.setPosition(pos);
	}

	void Lane::draw(sf::RenderWindow& window)
	{
		rect.setFillColor(sf::Color::Blue);
		window.draw(rect);
	}

	sf::Vector2f Lane::getPos()
	{
		return pos;
	}
}