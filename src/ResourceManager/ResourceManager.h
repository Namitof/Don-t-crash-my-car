#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager
{
private:
	sf::Font font;
	sf::Texture backgroundMenu;
	sf::Texture button;
	sf::Texture backgroundGame;
	sf::Texture car;
	sf::Texture bottle;
	sf::Texture obstacle;

public:
	ResourceManager();
	~ResourceManager();

	sf::Font& getFont();
	sf::Texture& getBackgroundMenu();
	sf::Texture& getButton();
	sf::Texture& getBackgroundGame();
	sf::Texture& getCar();
	sf::Texture& getBottle();
	sf::Texture& getObstacle();
};