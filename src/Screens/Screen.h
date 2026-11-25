#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Screen
{
private:

public:
	Screen();
	~Screen();

	virtual void update() = 0;

	virtual void draw(sf::RenderWindow& window) = 0;
};