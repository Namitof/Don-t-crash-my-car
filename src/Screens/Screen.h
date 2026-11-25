#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Screens/Screens.h"

class Screen
{
protected:
	sf::RenderWindow& window;

public:
	Screen(sf::RenderWindow& window);
	~Screen();

	virtual Screens update() = 0;

	virtual void draw() = 0;
};