#include "Player.h"
#include "../Walkable/Walkable.h"

Player::Player(const sf::Texture &texture) : Drawable{texture, {0, 0}}
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
    auto elapsedTime = this->clock.getElapsedTime().asSeconds();
    bool nextTexturePartShouldBeDrawn = elapsedTime > 0.4;
    if (nextTexturePartShouldBeDrawn)
    {
        sf::IntRect textureRect = this->sprite.getTextureRect();
        const sf::Texture &texture = this->sprite.getTexture();
        if (textureRect.position.x < texture.getSize().x - textureRect.size.x)
        {
            textureRect.position.x += textureRect.size.x;
        }
        else
            textureRect.position.x = 0;

        this->sprite.setTextureRect(textureRect);
        this->clock.restart();
    }
    return this->sprite;
}