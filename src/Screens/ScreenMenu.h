#pragma once

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

namespace DontCrashMyCar
{

	const float INITIAL_POS_X = 120.0f;
	const float INITIAL_PLAY_POS_Y = 200.0f;
	const float INITIAL_RULES_POS_Y = 300.0f;
	const float INITIAL_EXIT_POS_Y = 400.0f;

	const unsigned int CREDITS_SIZE = 30;
	const sf::Color CREDITS_COLOR = sf::Color::Black;
	const sf::Vector2f CREDITS_POS = { 80.0f, 550.0f };
	const float CREDITS_OFFSET = 30.0f;

	const unsigned int TITLE_SIZE = 80;
	const sf::Vector2f TITLE_POS = { 80.0f, 50.0f };
	const sf::Color TITLE_COLOR = sf::Color::Red;

	class ScreenMenu : public Screen
	{
	private:
		sf::Sprite background;
		Button play;
		Button rules;
		Button exit;
		sf::Text title;
		sf::Text credits;
		sf::Text creditsA;
		sf::Text creditsB;
		sf::Text creditsC;

	public:
		ScreenMenu(sf::RenderWindow& window, sf::Font& font, sf::Texture& backgroundMenu, sf::Texture& buttonTexture);
		~ScreenMenu();

		Screens update(float deltaTime) override;

		void draw() override;
	};
}