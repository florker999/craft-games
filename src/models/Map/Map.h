#include <vector>
#include "../Tile/Tile.h"
#include "../Terrain/Terrain.h"
#include "../Player/Player.h"

#ifndef MAP_H
#define MAP_H

#pragma once

class Map
{
public:
    Map(int width, int height, int tileSize, sf::Texture &playerTexture);
    ~Map();

    enum Direction {
        Up,
        Right,
        Left,
        Down
    };

    void fill(Terrain base);
    void draw(sf::RenderWindow &window);
    void movePlayer(Direction direction);
    void placePlayer(sf::Vector2f position, Player& player);

private:
    std::vector<std::vector<Tile>> tiles;
    int playerX;
    int playerY;
};

#endif