#include <SFML/Graphics.hpp>
#include "../Tile/Tile.h"

#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class Player
{
public:
    Player(sf::Texture &texture);
    ~Player();

    void setPosition(const sf::Vector2f &position);
    void setTile(Tile *tile);
    void move(const sf::Vector2f &move);
    void move(const Tile::Direction &direction);
    void draw(sf::RenderWindow &window) const;

    operator sf::Sprite();

private:
    sf::Sprite spr;
    Tile *tile;
};

#endif