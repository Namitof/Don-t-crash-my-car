#include "Car.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Car::Car()
{
	pos.x = 320 + 255;
	pos.y = 450;
	lane = 1;
	points = 0;
	width = 150.0f;
	height = 90.0f;
	isAlive = true;
	canMove = true;

	rect = sf::RectangleShape({ width, height });
}

Car::~Car()
{

}

void Car::move()
{
	if ( ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ) && lane != 0 && canMove)
	{
		pos.x -= 255;
		lane--;
		canMove = false;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && lane != 2 && canMove)
	{
		pos.x += 255;
		lane++;
		canMove = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		canMove = true;
	}

	rect.setPosition(pos);
}

void Car::addPoints()
{
	points += 30;
}

void Car::checkCollision(Point& point, Obstacle& obstacle)
{
	if (pos.y < point.getPos().y + point.getHeight() && pos.y + height > point.getPos().y && pos.x < point.getPos().x + point.getWidth() && pos.x + width > point.getPos().x)
	{
		addPoints();
		point.spawn();
	}
	else if (pos.y < obstacle.getPos().y + obstacle.getHeight() && pos.y + height > obstacle.getPos().y && pos.x < obstacle.getPos().x + obstacle.getWidth() && pos.x + width > obstacle.getPos().x)
	{
		isAlive = false;
	}
}

void Car::draw(sf::RenderWindow& window)
{
	rect.setFillColor(sf::Color::White);
	window.draw(rect);
}

bool Car::getIsAlive()
{
	return isAlive;
}

sf::Vector2f Car::getPos()
{
	return pos;
}

int Car::getPoints()
{
	return points;
}
