#pragma once
#include <SFML/System/Vector2.hpp>
class Point
{
public:
	Point();
	~Point();

	sf::Vector2f getPos();
	int getHeight();
	int getWidth();
	void spawn();
	void move(float dt);
	void draw();

private:
	sf::Vector2f pos;

	int lane;
	int width;
	int height;
	float speed;
};
