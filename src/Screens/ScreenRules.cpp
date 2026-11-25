#include "ScreenRules.h"

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

ScreenRules::ScreenRules(sf::RenderWindow& window, sf::Font& font, sf::Texture& buttonTexture, sf::Texture& backgroundMenu) :
	Screen(window), 
	back({ INITIAL_POS_X, INITIAL_BACK_POS_Y }, "Back", font, buttonTexture),
	title(font, "= RULES =", TITLE_SIZE),
	line1(font, "Press A to move left.", CREDITS_SIZE),
	line2(font, "Press D to move right.", CREDITS_SIZE),
	line3(font, "Avoid obstacles or lose a life.", CREDITS_SIZE),
	line4(font, "Collect bottles to score points.", CREDITS_SIZE),
	background(backgroundMenu)
{
	title.setPosition(TITLE_RULES_POS);
	title.setFillColor(TITLE_COLOR);

	line1.setPosition({ RULES_POS.x,  RULES_POS.y + (RULES_OFFSET * 1) });
	line1.setFillColor(CREDITS_COLOR);

	line2.setPosition({ RULES_POS.x,  RULES_POS.y + (RULES_OFFSET * 2)});
	line2.setFillColor(CREDITS_COLOR);

	line3.setPosition({ RULES_POS.x,  RULES_POS.y + (RULES_OFFSET * 3) });
	line3.setFillColor(CREDITS_COLOR);

	line4.setPosition({ RULES_POS.x,  RULES_POS.y + (RULES_OFFSET * 4) });
	line4.setFillColor(CREDITS_COLOR);

	background.setPosition({ 0.0f,0.0f });
}

ScreenRules::~ScreenRules()
{}

Screens ScreenRules::update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	back.update(mousePosition);

	if (back.isClicked(mousePosition))
	{
		return Screens::Menu;
	}

	return Screens::Rules;
}

void ScreenRules::draw()
{
	window.draw(background);
	window.draw(title);
	window.draw(line1);
	window.draw(line2);
	window.draw(line3);
	window.draw(line4);
	back.draw(window);
}