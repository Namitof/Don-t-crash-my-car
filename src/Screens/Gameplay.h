#pragma once

#include "Screen.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"
#include "Entities/Car.h"
#include "Entities/Lane.h"
#include "Entities/Obstacle.h"
#include "Entities/Point.h"

namespace DontCrashMyCar
{
	const float POS_X = 15.0f;
	const float POS_Y = 650.0f;
	const unsigned int SCORE_SIZE = 60;
	const unsigned int GAMEOVER_SIZE = 120;
	const sf::Vector2f GAMEOVER_SPAWN = { 340.0f , 50.0f };

	class Gameplay : public Screen
	{
	private:
		sf::Sprite backgroundOne;
		sf::Sprite backgroundTwo;
		sf::Sprite carSprite;
		sf::Sprite pointSprite;
		sf::Sprite obstacleSprite;
		sf::Text score;
		sf::Text gameOver;
		Car car;
		Lane currentLane;
		Lane nextLane;
		Obstacle obstacle;
		Point point;
		Button back;

	public:
		Gameplay(sf::RenderWindow& window, sf::Font& font, sf::Texture& buttonTexture, sf::Texture& background, sf::Texture& carTexture, sf::Texture& pointTexture, sf::Texture& obstacleTexture);
		~Gameplay();

		void initGameplay();

		Screens update(float deltaTime) override;

		void draw() override;
	};
}