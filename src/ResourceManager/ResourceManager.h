#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager
{
private:
	sf::Font font;
	sf::Sprite backgroundMenu;
	sf::Sprite button;

public:
	ResourceManager();
	~ResourceManager();

	sf::Font& getFont();
	sf::Texture& getBackgroundMenu();
	sf::Texture& getButton();
};