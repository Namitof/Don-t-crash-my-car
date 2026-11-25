#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager
{
private:
	sf::Font font;

public:
	ResourceManager();
	~ResourceManager();

	sf::Font getFont();

};