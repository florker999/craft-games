#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../Tile/Tile.h"
#include "../Drawable/Drawable.h"
#include "../Animation/Animation.h"

#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class Player : public Animation
{
public:
    Player(const sf::Texture &texture);
    ~Player();
    operator sf::Sprite();

    void setTile(Tile *tile);
    void move(const sf::Vector2f &move);
    void move(const Tile::Direction &direction);

private:
    Tile *tile;
};

#endif