#include "ResourceManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace DontCrashMyCar
{
	ResourceManager::ResourceManager()
	{
		font = sf::Font("res/fonts/EvilScratch.ttf");
		backgroundMenu = sf::Texture("res/backgrounds/background_menu.png");
		button = sf::Texture("res/assets/Button.png");
		backgroundGame = sf::Texture("res/backgrounds/backgorund_gameplay.png");
		car = sf::Texture("res/assets/BabyTest.png");
		bottle = sf::Texture("res/assets/Bottle.png");
		obstacle = sf::Texture("res/assets/Block.png");
		musicMenu = sf::Music("res/music/mainMenu.wav");
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

	sf::Texture& ResourceManager::getBackgroundGame()
	{
		return backgroundGame;
	}

	sf::Texture& ResourceManager::getCar()
	{
		return car;
	}

	sf::Texture& ResourceManager::getBottle()
	{
		return bottle;
	}

	sf::Texture& ResourceManager::getObstacle()
	{
		return obstacle;
	}

	sf::Music& ResourceManager::getMusicMenu()
	{
		return musicMenu;
	}
}