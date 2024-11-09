/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Contrallable.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Loader.hpp"
#include "Registry.hpp"

namespace rt {

    /// @brief description 
    /// @param upKey UP
    /// @param downKey DOWN
    /// @param leftKey LEFT
    /// @param rightKey RIGHT
    /// @param shootKey SHOOT
    /// @param interactKey INTERACT
    struct Controllable_t {
        sf::Keyboard::Key upKey;
        sf::Keyboard::Key downKey;
        sf::Keyboard::Key leftKey;
        sf::Keyboard::Key rightKey;
        sf::Keyboard::Key shootKey;
        sf::Keyboard::Key interactKey;
    };

    void ControllableSystem(rt::Registry &, Loader &);
    
};