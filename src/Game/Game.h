#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"

class Game
{
private:
	sf::Vector2u screenSize;
	sf::RenderWindow window;
	ResourceManager resourceManager;

	ScreenMenu* menu;

public:
	Game();
	~Game();

	void initScreens();

	void update();

	void draw();

	void run();
};