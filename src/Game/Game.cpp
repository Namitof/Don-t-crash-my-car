#include "Game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
#include "Screens/ScreenRules.h"
#include "Screens/Gameplay.h"

namespace DontCrashMyCar
{
	Game::Game() : resourceManager()
	{
		const unsigned int WIDTH = 1280;
		const unsigned int HEIGHT = 720;

		screenSize = { WIDTH , HEIGHT };

		window = sf::RenderWindow(sf::VideoMode(screenSize), "Don't crash my car");

		currentScreen = Screens::Menu;

		initScreens();
	}

	Game::~Game()
	{
		if (menu != nullptr)
		{
			delete menu;
			menu = nullptr;
		}

		if (gameplay != nullptr)
		{
			delete gameplay;
			gameplay = nullptr;
		}

		if (rules != nullptr)
		{
			delete rules;
			rules = nullptr;
		}
	}

	void Game::initScreens()
	{
		menu = new ScreenMenu(window, resourceManager.getFont(), resourceManager.getBackgroundMenu(), resourceManager.getButton());
		gameplay = new Gameplay(window, resourceManager.getFont(), resourceManager.getButton(), resourceManager.getBackgroundGame(), resourceManager.getCar(), resourceManager.getBottle(), resourceManager.getObstacle());
		rules = new ScreenRules(window, resourceManager.getFont(), resourceManager.getButton(), resourceManager.getBackgroundMenu());
	}

	void Game::update(float deltaTime)
	{
		gameIsRunning = true;

		switch (currentScreen)
		{
		case Screens::Menu:
			if (menu != nullptr)
			{
				currentScreen = menu->update(deltaTime);
			}
			break;
		case Screens::Play:
			if (gameplay != nullptr)
			{
				currentScreen = gameplay->update(deltaTime);
			}
			break;
		case Screens::Rules:
			if (rules != nullptr)
			{
				currentScreen = rules->update(deltaTime);
			}
			break;
		case Screens::Exit:
			gameIsRunning = false;
			break;
		default:
			break;
		}
	}

	void Game::draw()
	{
		window.clear();
		switch (currentScreen)
		{
		case Screens::Menu:
			if (menu != nullptr)
			{
				menu->draw();
			}
			break;
		case Screens::Play:
			if (gameplay != nullptr)
			{
				gameplay->draw();
			}
			break;
		case Screens::Rules:
			if (rules != nullptr)
			{
				rules->draw();
			}
			break;
		case Screens::Exit:
			break;
		default:
			break;
		}
		window.display();
	}

	void Game::run()
	{
		resourceManager.getMusicMenu().play();
		resourceManager.getMusicMenu().setLooping(true);

		float deltaTime = 0.0f;
		while (window.isOpen() && gameIsRunning)
		{
			deltaTime = clockDeltaTime.restart().asSeconds();

			while (const std::optional event = window.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
					window.close();
			}

			update(deltaTime);

			draw();
		}
	}
}