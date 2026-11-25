#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
#include "Screens/Gameplay.h"

class ScreenRules : public Screen
{
private:
	Button rules;

public:
	ScreenRules(sf::RenderWindow& window, sf::Font& font);
	~ScreenRules();

	Screens update() override;

	void draw() override;
};