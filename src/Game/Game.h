#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
#include "Screens/Gameplay.h"

class Game
{
private:
	sf::Vector2u screenSize;
	sf::RenderWindow window;
	ResourceManager resourceManager;

	Screens currentScreen;
	ScreenMenu* menu;
	ScreenMenu* rules;
	ScreenMenu* exit;
	Gameplay* gameplay;

public:
	Game();
	~Game();

	void initScreens();

	void update();

	void draw();

	void run();
};