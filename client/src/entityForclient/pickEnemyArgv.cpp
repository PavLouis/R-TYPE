/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** pickProjectilArgv
*/

#include <SFML/Network.hpp>

void pickEnemyArgv(sf::Packet &receivedPacket, float &x, float &y, sf::Int8 &live,
                   sf::Int8 &type) noexcept {
  receivedPacket >> x >> y >> live >> type;
}