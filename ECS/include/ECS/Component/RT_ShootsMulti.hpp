/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_parallax
*/

#include "Registry.hpp"
#include <SFML/Graphics.hpp>

#pragma once

namespace rt {

    /**
     * @brief Represent the multi shoot 
    **/
    class ShootsMulti
    {
    private:
        sf::Clock clock;
        float speed;
    public:
        ShootsMulti() noexcept;
        ~ShootsMulti() noexcept = default;
        sf::Clock getClock() const noexcept;
        void restartClock() noexcept;
    };

    void shootMultiPlayerSysteme(rt::Registry &);
}


