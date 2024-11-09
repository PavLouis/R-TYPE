/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** getEntity
*/

#pragma once

#include <SFML/Network.hpp>

void pickProjectilArgv(sf::Packet &receivedPacket, float &x, float &y) noexcept;
void pickEnemyArgv(sf::Packet &receivedPacket, float &x, float &y, sf::Int8 &live,
                   sf::Int8 &type) noexcept;
