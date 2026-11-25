#include "ScreenRules.h"

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

ScreenRules::ScreenRules(sf::RenderWindow& window, sf::Font& font) : Screen(window), back({ INITIAL_POS_X, INITIAL_BACK_POS_Y }, "Back", font)
{

}

ScreenRules::~ScreenRules()
{}

Screens ScreenRules::update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	back.update(mousePosition);

	if (back.isClicked(mousePosition))
	{
		return Screens::Menu;
	}

	return Screens::Rules;
}

void ScreenRules::draw()
{
	back.draw(window);
}