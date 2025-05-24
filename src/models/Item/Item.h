#include "../Drawable/Drawable.h"

#ifndef ITEM_H
#define ITEM_H

#pragma once

class Item : public Drawable
{
public:
    Item(const sf::Texture &texture, const sf::Vector2f &position);
    ~Item();

private:

};

#endif