#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Obstacle.h"
#include "Point.h"

class Car
{
private:
	sf::Vector2f pos;
	float width;
	float height;
	int points;
	int lane;
	bool isAlive;
	bool canMove;
	sf::RectangleShape rect;

public:
	Car();
	~Car();
	void move();
	void addPoints();
	void checkCollision(Point& point, Obstacle& obstacle);
	void draw(sf::RenderWindow& window);
	bool getIsAlive();
	sf::Vector2f getPos();
	int getPoints();
};
