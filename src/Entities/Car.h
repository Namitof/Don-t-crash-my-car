#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Obstacle.h"
#include "Point.h"

const float CAR_WIDTH = 150.0f;
const float CAR_HEIGHT = 90.0f;
const float CAR_POS_Y = 450.0f;
const float CAR_POS_X = 320.0f + 255.0f;
const float LANE_OFFSET = 255.0f;
const int SCORE_ADD_VALUE = 30;

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
