#pragma once

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"

class ScreenMenu : public Screen
{
private:
	sf::Font font;
	Button button;

public:
	ScreenMenu(sf::Font font);
	~ScreenMenu();

	void update() override;

	void draw(sf::RenderWindow& window) override;
};
