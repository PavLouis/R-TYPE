/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Position.hpp
*/

#include "Registry.hpp"

#pragma once

namespace rt {

    /**
     * @brief Represent the position of the entity
    **/
    struct Pos_t
    {
        float x;
        float y;
    };

    void PositionSystem(rt::Registry &);

};
