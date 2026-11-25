#include "ScreenRules.h"

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

ScreenRules::ScreenRules(sf::RenderWindow& window, sf::Font& font) : Screen(window), rules({ INITIAL_POS_X, INITIAL_PLAY_POS_Y }, "Rules", font)
{

}

ScreenRules::~ScreenRules()
{}

Screens ScreenRules::update()
{
	return Screens::Menu;
}

void ScreenRules::draw()
{
}