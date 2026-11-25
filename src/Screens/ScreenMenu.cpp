#include "Screen.h"
#include "ScreenMenu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

ScreenMenu::ScreenMenu(sf::Font font) : Screen()
{
	this->font = font;
	button = Button({ 0.0f,0.0f }, "testeo", this->font);
}

ScreenMenu::~ScreenMenu()
{
}

void ScreenMenu::update()
{

}

void ScreenMenu::draw(sf::RenderWindow& window)
{
	button.draw(window);
}