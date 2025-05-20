#pragma once
#include <SFML/Graphics.hpp>

class Terrain
{
private:
    sf::Sprite spr;

public:
    Terrain(sf::Texture &texture, sf::Vector2f position);
    ~Terrain();

    void print(sf::RenderWindow& window);

    operator sf::Sprite();
};