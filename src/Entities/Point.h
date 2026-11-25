#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace DontCrashMyCar
{
	const float POINT_INITIAL_POS_Y = -200;
	const float POINT_HEIGTH = 150.0f;
	const float POINT_WIDTH = 150.0f;
	const float POINT_SPEED = 300;
	const float POINT_SPAWN_LANE_1 = 320.0f;
	const float POINT_LANE_OFFSET = 255.0f;

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
}