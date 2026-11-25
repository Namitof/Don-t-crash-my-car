#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const sf::Vector2f BUTTON_SIZE = { 50.0f, 50.0f };
const sf::Color SELECT_COLOR = sf::Color::Green;
const sf::Color DEFAULT_COLOR = sf::Color::Blue;

class Button
{
private:
	sf::RectangleShape* hitbox;
	sf::Text* text;
	sf::Font* font;
	sf::Color* currentColor;

public:
	Button();
	Button(sf::Vector2f position, std::string text, sf::Font font);
	~Button();

	bool isHovered();

	bool isClicked();

	void update();

	void draw(sf::RenderWindow& window);
};