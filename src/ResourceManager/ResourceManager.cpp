#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

ResourceManager::ResourceManager()
{
	font = sf::Font("res/fonts/EvilScratch.ttf");
	backgroundMenu = sf::Texture("res/backgrounds/background_menu.png");
	button = sf::Texture("res/assets/Button.png");
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