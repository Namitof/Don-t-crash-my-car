#include "Game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
#include "Screens/ScreenRules.h"
#include "Screens/Gameplay.h"

Game::Game()
{
	const unsigned int WIDTH = 1280;
	const unsigned int HEIGHT = 720;

	screenSize = { WIDTH , HEIGHT };

    window = sf::RenderWindow(sf::VideoMode(screenSize), "Don't crash my car");

    resourceManager = ResourceManager();

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
    gameplay = new Gameplay(window, resourceManager.getFont(), resourceManager.getButton());
    rules = new ScreenRules(window, resourceManager.getFont(), resourceManager.getButton(), resourceManager.getBackgroundMenu());
}

void Game::update()
{
    gameIsRunning = true;

    switch (currentScreen)
    {
    case Screens::Menu:
        currentScreen = menu->update();
        break;
    case Screens::Play:
        currentScreen = gameplay->update();
        break;
    case Screens::Rules:
        currentScreen = rules->update();
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
        menu->draw();
        break;
    case Screens::Play:
        gameplay->draw();
        break;
    case Screens::Rules:
        rules->draw();
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
    float deltaTime = 0.0f;
    while (window.isOpen() && gameIsRunning)
    {
        deltaTime = clockDeltaTime.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        update();

        draw();
    }
}

//Game::Game() : backgroundMenu(resourceManager.getBackgroundMenu())
//{
//    sf::Vector2u texSize = resourceManager.getBackgroundMenu().getSize();
//    backgroundMenu.setScale({ (float)WIDTH / texSize.x, (float)HEIGHT / texSize.y });
//}