#pragma once
#include <SFML/System/Vector2.hpp>
#include "Obstacle.h"
#include "Point.h"
class Car
{
public:
	Car();
	~Car();
	void move();
	void addPoints();
	void checkCollision(Point& point, Obstacle& obstacle);
	void draw();
	

private:
	sf::Vector2f pos;
	int width;
	int height;
	int points;
	int lane;
	bool isAlive;
	bool canMove;
};
