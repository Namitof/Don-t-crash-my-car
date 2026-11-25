#include "Button.h"

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace DontCrashMyCar
{
	Button::Button(sf::Vector2f position, std::string label, sf::Font& font, sf::Texture& texture) :
		hitbox(BUTTON_SIZE), text(font, label, TEXT_SIZE),
		currentColor(DEFAULT_COLOR),
		sprite(texture)
	{
		hitbox.setPosition(position);
		text.setPosition({ position.x + 30.0f, position.y + 10.0f });
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
			sprite.setColor(SPRITE_SELECT_COLOR);
			currentColor = SELECT_COLOR;
			hitbox.setFillColor(currentColor);
		}
		else
		{
			sprite.setColor(sf::Color::White);
			currentColor = DEFAULT_COLOR;
			hitbox.setFillColor(currentColor);
		}
	}

	void Button::draw(sf::RenderWindow& window)
	{
#ifdef _DEBUG
		window.draw(hitbox);
#endif // _DEBUG

		window.draw(sprite);
		window.draw(text);
	}
}