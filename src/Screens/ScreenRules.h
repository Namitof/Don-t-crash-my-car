#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
#include "Screens/Gameplay.h"

const float INITIAL_BACK_POS_Y = 600.0f;

const sf::Vector2f TITLE_RULES_POS = { 80.0f, 50.0f };

const unsigned int RULES_SIZE = 30;
const sf::Color RULES_COLOR = sf::Color::Black;
const sf::Vector2f RULES_POS = { 80.0f, 150.0f };
const float RULES_OFFSET = 40.0f;

class ScreenRules : public Screen
{
private:
	sf::Sprite background;
	Button back;
	sf::Text title;
	sf::Text line1;
	sf::Text line2;
	sf::Text line3;
	sf::Text line4;

public:
	ScreenRules(sf::RenderWindow& window, sf::Font& font, sf::Texture& buttonTexture, sf::Texture& backgroundMenu);
	~ScreenRules();

	Screens update() override;

	void draw() override;
};