#include "Screen.h"
#include "ScreenMenu.h"
#include "ScreenRules.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

ScreenMenu::ScreenMenu(sf::RenderWindow& window, sf::Font& font, sf::Texture& backgroundMenu, sf::Texture& buttonTexture) : Screen(window),
play({ INITIAL_POS_X, INITIAL_PLAY_POS_Y }, "Play", font, buttonTexture),
rules({ INITIAL_POS_X, INITIAL_RULES_POS_Y }, "Rules", font, buttonTexture),
exit({ INITIAL_POS_X, INITIAL_EXIT_POS_Y }, "Exit", font, buttonTexture),
title(font, "Don't crash my car", TITLE_SIZE),
credits(font, "Game by: ", CREDITS_SIZE),
creditsA(font, "- Mercedes Ramirez Diaz", CREDITS_SIZE),
creditsB(font, "- Nahuel Suarez", CREDITS_SIZE),
creditsC(font, "- Santino Giuffrida Castillo", CREDITS_SIZE),
background(backgroundMenu)
{
	title.setPosition(TITLE_POS);
	title.setFillColor(TITLE_COLOR);

	credits.setPosition({ CREDITS_POS.x,  CREDITS_POS.y});
	credits.setFillColor(CREDITS_COLOR);

	creditsA.setPosition({ CREDITS_POS.x, CREDITS_POS.y + CREDITS_OFFSET });
	creditsA.setFillColor(CREDITS_COLOR);

	creditsB.setPosition({ CREDITS_POS.x, CREDITS_POS.y + (CREDITS_OFFSET * 2) });
	creditsB.setFillColor(CREDITS_COLOR);

	creditsC.setPosition({ CREDITS_POS.x, CREDITS_POS.y + (CREDITS_OFFSET * 3) });
	creditsC.setFillColor(CREDITS_COLOR);

	background.setPosition({ 0.0f,0.0f });
}

ScreenMenu::~ScreenMenu()
{
}

Screens ScreenMenu::update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	play.update(mousePosition);
	rules.update(mousePosition);
	exit.update(mousePosition);

	if (play.isClicked(mousePosition))
	{
		return Screens::Play;
	}
	else if (rules.isClicked(mousePosition))
	{
		return Screens::Rules;
	}
	else if (exit.isClicked(mousePosition))
	{
		return Screens::Exit;
	}

	return Screens::Menu;
}

void ScreenMenu::draw()
{
	window.draw(background);
	window.draw(title);
	window.draw(credits);
	window.draw(creditsA);
	window.draw(creditsB);
	window.draw(creditsC);
	play.draw(window);
	rules.draw(window);
	exit.draw(window);
}