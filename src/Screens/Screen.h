#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Screens/Screens.h"

namespace DontCrashMyCar
{
	class Screen
	{
	protected:
		sf::RenderWindow& window;

	public:
		Screen(sf::RenderWindow& window);
		virtual ~Screen();

		virtual Screens update(float deltaTime) = 0;

		virtual void draw() = 0;
	};
}