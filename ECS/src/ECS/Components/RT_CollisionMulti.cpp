/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_CollisionMulti
*/

#include "RT_CollisionMulti.hpp"

rt::CollisionMulti::CollisionMulti(
    sf::Vector2f rect,
    std::function<void(Registry &, Entity &)> funcCollision) noexcept {
  inCollision = funcCollision;
  Collision = false;
  Rect = rect;
}

std::function<void(rt::Registry &, Entity &)> rt::CollisionMulti::getFuncInCollision() const
{
    return this->inCollision;
}

bool rt::CollisionMulti::getCollision() const
{
    return this->Collision;
}

void rt::CollisionMulti::setCollision(bool state)
{
    this->Collision = state;
}

sf::Vector2f rt::CollisionMulti::getRect() const
{
    return this->Rect;
}

void rt::CollisionMulti::setRect(sf::Vector2f state)
{
    this->Rect = state;
}
