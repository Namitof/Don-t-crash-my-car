#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const sf::Vector2f BUTTON_SIZE = { 180.0f, 60.0f };
const unsigned int TEXT_SIZE = 20;
const sf::Color SELECT_COLOR = sf::Color::Green;
const sf::Color DEFAULT_COLOR = sf::Color::Blue;

class Button
{
private:
	sf::RectangleShape hitbox;
	sf::Text text;
	sf::Color currentColor;

public:
	Button(sf::Vector2f position, std::string label, sf::Font& font);

	bool isHovered(sf::Vector2i mousePosition);
	bool isClicked(sf::Vector2i mousePosition);
	void update(sf::Vector2i mousePosition);
	void draw(sf::RenderWindow& window);
};