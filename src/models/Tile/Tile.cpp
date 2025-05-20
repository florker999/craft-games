#include "Tile.h"

Tile::Tile(const sf::Vector2f &position) : position{position}, topNeighbour{nullptr}, rightNeighbour{nullptr}, botNeighbour{nullptr}, leftNeighbour{nullptr}
{
}

Tile::~Tile()
{
}

void Tile::addLayer(sf::Sprite layer)
{
    layer.setPosition(this->position);
    this->layers.push_back(layer);
}

sf::Sprite Tile::popLayer()
{
    auto layer = this->layers.back();
    this->layers.pop_back();
    return layer;
}

const sf::Vector2f &Tile::getPosition() const
{
    return this->position;
}

void Tile::draw(sf::RenderWindow &window)
{
    for (sf::Sprite layer : this->layers)
        window.draw(layer);
}

Tile *Tile::getNeighbour(const Tile::Direction &direction)
{
    switch (direction)
    {
    case Direction::Up:
        return this->topNeighbour;

    case Direction::Right:
        return this->rightNeighbour;

    case Direction::Down:
        return this->botNeighbour;

    case Direction::Left:
        return this->leftNeighbour;
    }
}
