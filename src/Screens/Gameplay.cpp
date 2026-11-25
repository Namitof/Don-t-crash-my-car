#pragma once
#include "Gameplay.h"
#include "Screen.h"

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UI/Button.h"
#include "Screens/Screens.h"

Gameplay::Gameplay(sf::RenderWindow& window, sf::Font& font, sf::Texture& buttonTexture, sf::Texture& background, sf::Texture& carTexture, sf::Texture& pointTexture, sf::Texture& obstacleTexture) :
	Screen(window),
	back({ POS_X, POS_Y }, "BACK", font, buttonTexture),
	car(),
	currentLane({ 0.0f, 0.0f }),
	nextLane({ 0.0f, -720.0f }),
	obstacle(),
	point(),
	backgroundOne(background),
	backgroundTwo(background),
	carSprite(carTexture),
	pointSprite(pointTexture),
	obstacleSprite(obstacleTexture),
	score(font, "Score: 0", SCORE_SIZE)
{
	score.setFillColor(sf::Color::Black);
}

Gameplay::~Gameplay()
{

}

void Gameplay::initGameplay()
{
	car = Car();
	currentLane = Lane({ 0.0f, 0.0f });
	nextLane = Lane({ 0.0f, -720.0f });
	obstacle = Obstacle();
	point = Point();
}

Screens Gameplay::update(float deltaTime)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	if (car.getIsAlive())
	{
		currentLane.move(deltaTime);
		nextLane.move(deltaTime);
		obstacle.move(deltaTime);
		point.move(deltaTime);
		car.move();
		car.checkCollision(point, obstacle);

		backgroundOne.setPosition({currentLane.getPos()});
		backgroundTwo.setPosition({nextLane.getPos()});
		carSprite.setPosition(car.getPos());
		pointSprite.setPosition(point.getPos());
		obstacleSprite.setPosition(obstacle.getPos());

		score.setString("Score: " + std::to_string(car.getPoints()));
	}
	
	back.update(mousePosition);
	if (back.isClicked(mousePosition))
	{
		initGameplay();
		return Screens::Menu;
	}

	return Screens::Play;
}

void Gameplay::draw()
{
	window.draw(backgroundOne);
	window.draw(backgroundTwo);
	window.draw(carSprite);
	window.draw(obstacleSprite);
	window.draw(pointSprite);

#ifdef _DEBUG
	currentLane.draw(window);
	nextLane.draw(window);
	car.draw(window);
	obstacle.draw(window);
	point.draw(window);
#endif // _DEBUG
	
	back.draw(window);

	window.draw(score);
}