#include "Player.h"

Player::Player(sf::Texture &texture) : spr{texture}
{
}

Player::~Player()
{
}

void Player::setPosition(const sf::Vector2f &position)
{
    this->spr.setPosition(position);
}

void Player::setTile(Tile *tile)
{
    this->tile = tile;
    this->setPosition(tile->getPosition());
}

void Player::move(const sf::Vector2f &move)
{
    this->spr.move(move);
}

void Player::move(const Tile::Direction &direction)
{
    auto nextTile = this->tile->getNeighbour(direction);
    if (nextTile != nullptr)
    {
        this->tile = nextTile;
        this->setPosition(this->tile->getPosition());
    }
}

void Player::draw(sf::RenderWindow &window) const
{
    window.draw(this->spr);
}

Player::operator sf::Sprite()
{
    return this->spr;
}