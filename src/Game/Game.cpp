#include "Game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/Screens.h"
#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"
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
}

void Game::initScreens()
{
    menu = new ScreenMenu(window, resourceManager.getFont());
    gameplay = new Gameplay(window, resourceManager.getFont());
}

void Game::update()
{
    switch (currentScreen)
    {
    case Screens::Menu:
        currentScreen = menu->update();
        break;
    case Screens::Play:
        currentScreen = gameplay->update();
        break;
    case Screens::Rules:
        break;
    case Screens::Exit:
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
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        update();

        draw();
    }
}