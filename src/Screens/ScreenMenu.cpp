#include "Screen.h"
#include "ScreenMenu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

ScreenMenu::ScreenMenu(sf::RenderWindow& window, sf::Font& font) : Screen(window), play({ INITIAL_POS_X, INITIAL_POS_Y }, "Play", font)
{

}

ScreenMenu::~ScreenMenu()
{
}

Screens ScreenMenu::update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	play.update(mousePosition);

	if (play.isClicked(mousePosition))
	{
		return Screens::Play;
	}

	return Screens::Menu;
}

void ScreenMenu::draw()
{
	play.draw(window);
}