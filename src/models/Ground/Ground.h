#include "../Walkable/Walkable.h"
#include "../Drawable/Drawable.h"
#include "../Tile/Tile.h"

#ifndef GROUND_H
#define GROUND_H

#pragma once

class Ground : public Walkable, public Tile
{
public:
    Ground(const sf::Texture &texture, const sf::Vector2f &position);
    ~Ground();

private:

};

#endif