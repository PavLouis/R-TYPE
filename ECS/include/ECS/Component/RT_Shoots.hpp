/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Shoots.hpp
*/

#include <vector>
#include <string>

#include <SFML/Window.hpp>

#pragma once

namespace rt {

    /**
     * @brief Represent the shoot for an entity
    **/
    struct Shoot_t
    {
        std::string textureName;
        sf::Vector2f direction;
        float speed;
        sf::Int32 shootRate;
        sf::Clock clock;
    };

    struct Shoots_t {
        std::vector<rt::Shoot_t> shoots;
    };

};