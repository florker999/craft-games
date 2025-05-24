#include <SFML/Graphics.hpp>
#include "../Drawable/Drawable.h"

#ifndef TILE_H
#define TILE_H

#pragma once

class Tile : public Drawable
{
public:
    Tile(const sf::Texture &texture, const sf::Vector2f &position);
    virtual ~Tile();

    enum Direction
    {
        Up,
        Right,
        Left,
        Down
    };

    Tile *getNeighbour(const Tile::Direction &direction);
    Tile *topNeighbour;
    Tile *rightNeighbour;
    Tile *botNeighbour;
    Tile *leftNeighbour;

private:
};

#endif