/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Systems.hpp
*/

#include <SFML/Window.hpp>

#include "Registry.hpp"

#pragma once

namespace rt {

    struct systemsClocks_s {
        sf::Clock movementClock;
        sf::Clock killClock;
        sf::Clock controllableClock;
        sf::Clock drawableClock;
    };

    struct systemsRefreshRates_s {
        sf::Int32 movementRefreshRate;
        sf::Int32 killRefreshRate;
        sf::Int32 controllableRefreshRate;
        sf::Int32 drawableRefreshRate;
    };


};