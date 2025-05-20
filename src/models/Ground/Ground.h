#include "../Walkable/Walkable.h"
#include "../Drawable/Drawable.h"

#ifndef GROUND_H
#define GROUND_H

#pragma once

class Ground : public Walkable, Drawable
{
public:
    Ground(const sf::Texture &texture);
    ~Ground();

private:

};

#endif