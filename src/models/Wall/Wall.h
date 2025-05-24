#include "../Drawable/Drawable.h"
#include "../Tile/Tile.h"

#ifndef WALL_H
#define WALL_H

#pragma once

class Wall : public Tile
{
public:
    Wall(const sf::Texture &texture, const sf::Vector2f &position);
    ~Wall();

private:

};

#endif