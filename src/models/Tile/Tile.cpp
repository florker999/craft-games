#include "Tile.h"

Tile::Tile(const sf::Vector2f &position) : position{position}, topNeighbour{nullptr}, rightNeighbour{nullptr}, botNeighbour{nullptr}, leftNeighbour{nullptr}
{
}

Tile::~Tile()
{
}

const sf::Vector2f &Tile::getPosition() const
{
    return this->position;
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
