#include "Game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceManager/ResourceManager.h"
#include "Screens/ScreenMenu.h"

Game::Game()
{
	const unsigned int WIDTH = 1280;
	const unsigned int HEIGHT = 720;

	screenSize = { WIDTH , HEIGHT };

    window = sf::RenderWindow(sf::VideoMode(screenSize), "Don't crash my car");

    resourceManager = ResourceManager();

    initScreens();
}

Game::~Game()
{
    if (menu != nullptr)
    {
        delete menu;
        menu = nullptr;
    }
}

void Game::initScreens()
{
    menu = new ScreenMenu(resourceManager.getFont());
}

void Game::update()
{

}

void Game::draw()
{
    menu->draw(window);
}

void Game::run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        //draw();

        window.draw(shape);
        window.display();
    }
}