#include "Screen.h"
#include "ScreenMenu.h"
#include "ScreenRules.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

ScreenMenu::ScreenMenu(sf::RenderWindow& window, sf::Font& font) : Screen(window), 
play({ INITIAL_POS_X, INITIAL_PLAY_POS_Y }, "Play", font),
rules({ INITIAL_POS_X, INITIAL_RULES_POS_Y }, "Rules", font),
exit({ INITIAL_POS_X, INITIAL_EXIT_POS_Y }, "Exit", font)
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
	else if (play.isClicked(mousePosition))
	{
		return Screens::Credits;
	}
	else if (play.isClicked(mousePosition))
	{
		return Screens::Rules;
	}
	else if (play.isClicked(mousePosition))
	{
		return Screens::Exit;
	}

	return Screens::Menu;
}

void ScreenMenu::draw()
{
	play.draw(window);
	rules.draw(window);
	exit.draw(window);
}