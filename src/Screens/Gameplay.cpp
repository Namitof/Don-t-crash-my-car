#pragma once
#include "Gameplay.h"
#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

Gameplay::Gameplay(sf::RenderWindow& window, sf::Font& font) : Screen(window), back({ POS_X, POS_Y }, "BACK", font)
{

}

Gameplay::~Gameplay()
{

}

Screens Gameplay::update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	back.update(mousePosition);

	if (back.isClicked(mousePosition))
	{
		return Screens::Menu;
	}

	return Screens::Play;
}

void Gameplay::draw()
{
	back.draw(window);
}