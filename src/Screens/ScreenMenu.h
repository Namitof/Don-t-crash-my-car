#pragma once

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

const float INITIAL_POS_X = 120.0f;
const float INITIAL_POS_Y = 200.0f;

class ScreenMenu : public Screen
{
private:
	Button play;

public:
	ScreenMenu(sf::RenderWindow& window, sf::Font& font);
	~ScreenMenu();

	Screens update() override;

	void draw() override;
};
