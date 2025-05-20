#include <vector>
#include <SFML/Graphics.hpp>

#ifndef TILE_H
#define TILE_H

#pragma once

class Tile
{
public:
    Tile(const sf::Vector2f &position);
    ~Tile();

    void addLayer(sf::Sprite layer);
    sf::Sprite popLayer();
    const sf::Vector2f &getPosition() const;
    void draw(sf::RenderWindow &window);

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
    std::vector<sf::Sprite> layers; // later change maybe to item
    sf::Vector2f position;
};

#endif