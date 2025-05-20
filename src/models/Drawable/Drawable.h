#include <SFML/Graphics.hpp>

#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once

class Drawable
{
public:
    Drawable(const sf::Texture &texture); // probably requires adding the texture, position etc.
    ~Drawable();
    operator sf::Sprite();

private:
    sf::Sprite sprite;
};

#endif