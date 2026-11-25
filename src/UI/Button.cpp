#include "Button.h"

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Button::Button()
{
    hitbox = nullptr;
    text = nullptr;
    font = nullptr;
    currentColor = nullptr;
}

Button::Button(sf::Vector2f position, std::string text, sf::Font font)
{
    hitbox = new sf::RectangleShape(BUTTON_SIZE);
    this->font = new sf::Font(font);
    this->text = new sf::Text(*(this->font), text);
    this->currentColor = new sf::Color(DEFAULT_COLOR);
    hitbox->setPosition(position);
}

Button::~Button()
{
    if (hitbox != nullptr)
    {
        delete hitbox;
        hitbox = nullptr;
    }

    if (text != nullptr)
    {
        delete text;
        text = nullptr;
    }

    if (font != nullptr)
    {
        delete font;
        font = nullptr;
    }

    if (currentColor != nullptr)
    {
        delete currentColor;
        currentColor = nullptr;
    }
}

bool Button::isHovered()
{
    return false;
}

bool Button::isClicked()
{
    return false;
}

void Button::update()
{

}

void Button::draw(sf::RenderWindow& window)
{
    if (hitbox != nullptr)
    {
        hitbox->setFillColor(*(currentColor));
        window.draw(*(hitbox));
    }

    if (text != nullptr)
    {
        //text->setCharacterSize(30);
        //text->setFillColor(sf::Color::White);
        //text->setPosition({ 120.f, 130.f });
        //window.draw(*text);
    }
}