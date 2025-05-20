#include <SFML/Graphics.hpp>

#ifndef TILE_H
#define TILE_H

#pragma once

class Tile
{
public:
    Tile(const sf::Vector2f &position);
    ~Tile();

    const sf::Vector2f &getPosition() const;

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
    sf::Vector2f position;
};

#endif