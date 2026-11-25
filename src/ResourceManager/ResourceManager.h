#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager
{
private:
	sf::Font font;
	sf::Texture backgroundMenu;
	sf::Texture button;

public:
	ResourceManager();
	~ResourceManager();

	sf::Font& getFont();
	sf::Texture& getBackgroundMenu();
	sf::Texture& getButton();
};