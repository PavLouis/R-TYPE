/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_CollisionMulti
*/

#pragma once

#include <SFML/Graphics/Rect.hpp>
#include "RT_Size.hpp"
#include "RT_Position.hpp"

namespace rt {

    /**
     * @brief Handle all collision for multiplayer
    **/
    class CollisionMulti
    {
    private:
        std::function<void(Registry &, Entity &)> inCollision;
        bool Collision;
        sf::Vector2f Rect;
    public:
        CollisionMulti(sf::Vector2f rect, std::function<void(Registry &, Entity &)> inCollision) noexcept;
        ~CollisionMulti() noexcept = default;
        std::function<void(Registry &, Entity &)> getFuncInCollision() const;
        bool getCollision() const;
        void setCollision(bool state);
        sf::Vector2f getRect() const;
        void setRect(sf::Vector2f state);
    };
    
    void CollisionMultiSystem(rt::Registry &r);

};
