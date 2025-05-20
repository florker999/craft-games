#include "Terrain.h"

Terrain::Terrain(sf::Texture &texture, sf::Vector2f position) : spr{texture}
{
    spr.setPosition(position);
}

void Terrain::print(sf::RenderWindow &window)
{
    window.draw(spr);
}

Terrain::operator sf::Sprite()
{
    return this->spr;
}

Terrain::~Terrain()
{
}