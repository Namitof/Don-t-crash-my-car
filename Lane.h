#pragma once
#include <SFML/System/Vector2.hpp>
class Lane
{
public:
	Lane();
	~Lane();

private:
	sf::Vector2f pos;
	int width;
	int height;
};

