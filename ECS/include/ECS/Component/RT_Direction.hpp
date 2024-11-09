/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Direction
*/

#pragma once

#include "Registry.hpp"

namespace rt {

    /**
     * @brief Direction component
    **/
    struct Direction_t
    {
        float x;
        float y;
    };

    void DirectionSystem(rt::Registry &r);
}


