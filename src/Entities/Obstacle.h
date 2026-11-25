#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Point.h"

namespace DontCrashMyCar
{
	const float OBSTACLE_SPEED = 300.0f;
	const float OBSTACLE_WDITH = 150.0f;
	const float OBSTACLE_HEIGHT = 150.0f;
	const float OBSTACLE_INITIAL_POS_Y = -200.0f;
	const float OBSTACLE_SPAWN_LANE_1 = 320.0f;
	const float OBSTACLE_LANE_OFFSET = 255.0f;
	const float ACCELERATION_OBSTACLE = 10.0f;
	const float OBSTACLE_MAX_SPEED = 800.0f;


	class Obstacle
	{
	private:
		sf::Vector2f pos;
		int lane;
		float width;
		float height;
		float speed;
		sf::RectangleShape rect;

	public:
		Obstacle();
		~Obstacle();

		sf::Vector2f getPos();
		float getHeight();
		float getWidth();
		void spawn();
		void move(float dt);
		void draw(sf::RenderWindow& window);
		void checkCollision(Point& point);
	};
}