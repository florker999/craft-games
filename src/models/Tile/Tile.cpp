#include "Tile.h"

Tile::Tile(const sf::Texture &texture, const sf::Vector2f &position) : Drawable{texture, position}, topNeighbour{nullptr}, rightNeighbour{nullptr}, botNeighbour{nullptr}, leftNeighbour{nullptr}
{
}

Tile::~Tile()
{
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
