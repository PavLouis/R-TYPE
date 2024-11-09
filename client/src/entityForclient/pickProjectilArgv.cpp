/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** pickProjectilArgv
*/

#include <SFML/Network.hpp>

void pickProjectilArgv(sf::Packet &receivedPacket, float &x, float &y) noexcept {
  receivedPacket >> x >> y;
}