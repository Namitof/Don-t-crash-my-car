#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

ResourceManager::ResourceManager()
{
	font = sf::Font("res/fonts/EvilScratch.ttf");
}

ResourceManager::~ResourceManager()
{
	
}

sf::Font& ResourceManager::getFont()
{
	return font;
}

sf::Texture& ResourceManager::getBackgroundMenu()
{
	return backgroundMenu;
}

sf::Texture& ResourceManager::getButton()
{
	return button;
}