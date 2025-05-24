#include <vector>
#include <SFML/Graphics.hpp>
#include "../Tile/Tile.h"
#include "../Terrain/Terrain.h"
#include "../Player/Player.h"

#ifndef MAP_H
#define MAP_H

#pragma once

class Map
{
public:
    enum Direction
    {
        Up,
        Right,
        Left,
        Down
    };

    enum class GroundType
    {
        Void,
        Grass,
        Water,
        Wall,
    };

    // Map(int width, int height, int tileSize);
    Map(const std::vector<std::vector<GroundType>> &mapTemplate, const sf::Texture &grassTexture, const sf::Texture &waterTexture, int tileSize);
    ~Map();

    sf::Texture transparentTexture;

    //void fill(Tile *tile, Tile *tile2);
    void draw(sf::RenderWindow &window);
    void placePlayer(sf::Vector2f position, Player &player);

private:
    std::vector<std::vector<Tile *>> tiles;
    int playerX;
    int playerY;
};

#endif