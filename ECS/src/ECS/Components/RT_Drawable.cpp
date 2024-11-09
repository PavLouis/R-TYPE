/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Drawable.cpp
*/

#include <SFML/Graphics.hpp>

#include "RT_Drawable.hpp"

rt::Drawable::Drawable(sf::Texture const &texture,
                       std::vector<sf::IntRect> const &rects,
                       sf::Int32 const &frameRate, unsigned short const &layer,
                       sf::Vector2f const &size) {
  this->size = size;
  this->layer = layer;
  this->frameRate = frameRate;
  this->clock.restart();
  this->sprite.setTexture(texture);
  this->textureRects = rects;
  this->textureRectIndex = 0;
  if (this->textureRects.size())
    this->sprite.setTextureRect(this->textureRects[this->textureRectIndex]);
  this->sprite.setScale(this->size);
}

sf::Sprite rt::Drawable::getSprite() noexcept { return (this->sprite); }

sf::Time rt::Drawable::getElapsedTime() const noexcept {
  return (this->clock.getElapsedTime());
}

sf::Int32 rt::Drawable::getFrameRate() const noexcept {
  return (this->frameRate);
}

unsigned short rt::Drawable::getLayer() const noexcept { return (this->layer); }

void rt::Drawable::restartClock() noexcept { this->clock.restart(); }

void rt::Drawable::setSpriteRect(sf::IntRect const &rect) noexcept {
  this->sprite.setTextureRect(rect);
}

void rt::Drawable::setLayer(unsigned int const layer) noexcept {
  this->layer = layer;
}

void rt::Drawable::setPosition(sf::Vector2i const &v) noexcept {
  this->sprite.setPosition(v.x, v.y);
}

void rt::Drawable::updateSpriteTextureRect() noexcept {
  if (this->frameRate < this->clock.getElapsedTime().asMilliseconds()) {
    this->restartClock();
    this->textureRectIndex = this->textureRectIndex + 1;
    if (this->textureRectIndex + 1 > this->textureRects.size())
      this->textureRectIndex = 0;
    this->setSpriteRect(this->textureRects[this->textureRectIndex]);
  }
}