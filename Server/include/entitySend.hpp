/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** entitySend
*/

#pragma once

#include <SFML/Network.hpp>

void sendNewPoseProjectil(sf::Int16 id, float x, float y) noexcept;
void sendNewPoseEnemy(sf::Int16 id, float x, float y, sf::Int8 live,
                      sf::Int8 type) noexcept;
