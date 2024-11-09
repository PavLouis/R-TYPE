/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_ShootsMulti
*/

#include "RT_ShootsMulti.hpp"

rt::ShootsMulti::ShootsMulti() noexcept { this->clock.restart(); }

sf::Clock rt::ShootsMulti::getClock() const noexcept { return this->clock; }

void rt::ShootsMulti::restartClock() noexcept { this->clock.restart(); }
