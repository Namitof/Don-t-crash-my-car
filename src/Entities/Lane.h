#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace DontCrashMyCar
{
	const float LANE_SPEED = 300.0f;
	const float ACCELERATION_LANE = 10.0f;
	const float LANE_MAX_SPEED = 800.0f;

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
}