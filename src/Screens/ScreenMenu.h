#pragma once

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

const float INITIAL_POS_X = 120.0f;
const float INITIAL_PLAY_POS_Y = 200.0f;
const float INITIAL_RULES_POS_Y = 300.0f;
const float INITIAL_EXIT_POS_Y = 400.0f;

class ScreenMenu : public Screen
{
private:
	sf::Sprite background;
	Button play;
	Button rules;
	Button exit;

public:
	ScreenMenu(sf::RenderWindow& window, sf::Font& font, sf::Texture& backgroundMenu, sf::Texture& buttonTexture);
	~ScreenMenu();

	Screens update() override;

	void draw() override;
};
