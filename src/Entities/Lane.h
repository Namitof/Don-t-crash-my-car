#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Lane
{
private:
	sf::Vector2f pos;
	float width;
	float height;
	float speed;
	sf::RectangleShape rect;

public:
	Lane(sf::Vector2f pos);
	~Lane();
	void spawn();
	void move(float speed);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPos();
};

