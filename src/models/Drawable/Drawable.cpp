#include "Drawable.h"

Drawable::Drawable(const sf::Texture &texture, const sf::Vector2f &position) : sprite(texture)
{
    sprite.setPosition(position);
}

Drawable::~Drawable()
{
}

Drawable::operator sf::Sprite()
{
    return this->sprite;
}

void Drawable::move(const sf::Vector2f &move)
{
    this->sprite.move(move);
}

void Drawable::setPosition(const sf::Vector2f &position)
{
    this->sprite.setPosition(position);
}

const sf::Vector2f Drawable::getPosition() const
{
    return this->sprite.getPosition();
}