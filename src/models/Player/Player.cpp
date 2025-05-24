#include "Player.h"
#include "../Walkable/Walkable.h"

Player::Player(const sf::Texture &texture) : Animation{texture, {0, 0}, 6, sf::seconds(1)}
{
    sf::Vector2u textureSize = texture.getSize();
    int texturePartX{static_cast<int>(textureSize.x) / 6},
        texturePartY{static_cast<int>(textureSize.y)};
    this->sprite.setTextureRect(sf::IntRect{{0, 0}, {texturePartX, texturePartY}});
}

Player::~Player()
{
}

void Player::setTile(Tile *tile)
{
    this->tile = tile;
    this->setPosition(tile->getPosition());
}

void Player::move(const sf::Vector2f &move)
{
    this->move(move);
}

void Player::move(const Tile::Direction &direction)
{
    Tile *nextTile = this->tile->getNeighbour(direction);
    if (dynamic_cast<Walkable *>(nextTile) != nullptr)
    {
        this->tile = nextTile;
        this->setPosition(this->tile->getPosition());
    }
}

Player::operator sf::Sprite()
{
    this->animate();
    return this->sprite;
}