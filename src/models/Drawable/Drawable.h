#include <SFML/Graphics.hpp>

#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once

class Drawable
{
public:
    Drawable(const sf::Texture &texture, const sf::Vector2f &position); // probably requires adding the texture, position etc.
    virtual ~Drawable() = 0;
    operator sf::Sprite();

    void move(const sf::Vector2f &move);
    void setPosition(const sf::Vector2f &position);
    const sf::Vector2f getPosition() const;

protected:
    sf::Sprite sprite;
};

#endif