#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

ResourceManager::ResourceManager()
{
	font = sf::Font("res/EvilScratch.ttf");
}

ResourceManager::~ResourceManager()
{
	
}

sf::Font ResourceManager::getFont()
{
	return font;
}
