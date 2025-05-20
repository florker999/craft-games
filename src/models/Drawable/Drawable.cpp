#include "Drawable.h"

Drawable::Drawable(const sf::Texture &texture) : sprite(texture)
{
}

Drawable::~Drawable()
{
}

Drawable::operator sf::Sprite()
{
    return this->sprite;
}