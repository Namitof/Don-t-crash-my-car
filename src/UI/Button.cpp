#include "Button.h"

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Button::Button(sf::Vector2f position, std::string label, sf::Font& font, sf::Texture& texture) :
	hitbox(BUTTON_SIZE), text(font, label, TEXT_SIZE), 
	currentColor(DEFAULT_COLOR),
	sprite(texture)
{
	hitbox.setPosition(position);
	text.setPosition(position);
	sprite.setPosition(hitbox.getPosition());
}

bool Button::isHovered(sf::Vector2i mousePosition)
{
	sf::Vector2f rectanglePos = hitbox.getPosition();
	sf::Vector2f rectangleSize = hitbox.getSize();
	if ((mousePosition.x <= rectanglePos.x + rectangleSize.x && mousePosition.x >= rectanglePos.x) && (mousePosition.y <= rectanglePos.y + rectangleSize.y && mousePosition.y >= rectanglePos.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Button::isClicked(sf::Vector2i mousePosition)
{
	if (isHovered(mousePosition) && (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Button::update(sf::Vector2i mousePosition)
{
	if (isHovered(mousePosition))
	{
		currentColor = SELECT_COLOR;
	}
	else
	{
		currentColor = DEFAULT_COLOR;
	}
}

void Button::draw(sf::RenderWindow& window)
{
	hitbox.setFillColor(currentColor);
	window.draw(hitbox);
	window.draw(text);
	window.draw(sprite);
}