/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Collision.hpp
*/

#pragma once

#include <string>
#include <vector>

namespace rt {

    ///////////////////////
    /// @brief Component to store the layers to handle collision.
    /// @param belong vector of collision the entity belong to.
    /// @param collide vector of collision the entity collide to.
    //////////////////////
    struct Collision_t {
        std::vector<std::string> belong;
        std::vector<std::string> collide;
    };

};