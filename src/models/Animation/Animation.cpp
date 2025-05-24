#include "Animation.h"

Animation::Animation(const sf::Texture &texture, const sf::Vector2f &position, int maxFrame, sf::Time duration) : Drawable(texture, position), maxFrame{maxFrame}, frameDuration{duration.asSeconds() / maxFrame}, currentFrame{0}
{
}

Animation::~Animation()
{
}

void Animation::animate()
{
    const float elapsedTime = this->clock.getElapsedTime().asSeconds();
    const bool nextTexturePartShouldBeDrawn = elapsedTime > this->frameDuration;
    if (nextTexturePartShouldBeDrawn)
    {
        sf::IntRect textureRect = this->sprite.getTextureRect();
        const sf::Texture &texture = this->sprite.getTexture();
        this->currentFrame = ++this->currentFrame % this->maxFrame;
        const int frameWidth = textureRect.size.x;
        textureRect.position.x = frameWidth * (++this->currentFrame % this->maxFrame);
        this->sprite.setTextureRect(textureRect);
        this->clock.restart();
    }
}
