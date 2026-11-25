#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Point
{
private:
	sf::Vector2f pos;
	int lane;
	float width;
	float height;
	float speed;
	sf::RectangleShape rect;

public:
	Point();
	~Point();

	sf::Vector2f getPos();
	float getHeight();
	float getWidth();
	void spawn();
	void move(float dt);
	void draw(sf::RenderWindow& window);
};
