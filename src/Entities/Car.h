#pragma once
#include <SFML/System/Vector2.hpp>
class Car
{
public:
	Car();
	~Car();
	void move();
	void addPoints();
	void restLives();
	void checkCollision();
	sf::Vector2f getPos();
	

private:
	sf::Vector2f pos;
	int width;
	int height;
	int lives;
	int points;
};
