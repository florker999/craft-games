#include <SFML/System.hpp>
#include "../Drawable/Drawable.h"

#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once

class Animation : public Drawable
{
public:
    Animation(const sf::Texture &texture, const sf::Vector2f &position, int maxFrame, sf::Time duration);
    ~Animation();

private:
    int maxFrame;
    int currentFrame;
    float frameDuration;
    sf::Clock clock;

protected:
    void animate();
};

#endif