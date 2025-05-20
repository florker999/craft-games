#include "../Drawable/Drawable.h"

#ifndef WALL_H
#define WALL_H

#pragma once

class Wall : public Drawable
{
public:
    Wall(const sf::Texture &texture);
    ~Wall();

private:

};

#endif