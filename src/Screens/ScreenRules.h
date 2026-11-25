#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
#include "Screens/Gameplay.h"

const float INITIAL_BACK_POS_Y = 600.0f;

class ScreenRules : public Screen
{
private:
	Button back;

public:
	ScreenRules(sf::RenderWindow& window, sf::Font& font);
	~ScreenRules();

	Screens update() override;

	void draw() override;
};