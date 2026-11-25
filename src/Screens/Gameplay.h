#pragma once

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

const float POS_X = 500.0f;
const float POS_Y = 500.0f;

class Gameplay : public Screen
{
private:
	Button back;

public:
	Gameplay(sf::RenderWindow& window, sf::Font& font, sf::Texture& buttonTexture);
	~Gameplay();

	Screens update() override;

	void draw() override;
};