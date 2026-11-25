#pragma once
#include <SFML/System/Vector2.hpp>
class Lane
{
public:
	Lane(sf::Vector2f pos);
	~Lane();
	void spawn();
	void move(float speed);
	void draw();

private:
	sf::Vector2f pos;
	int width;
	int height;
	float speed;
};

