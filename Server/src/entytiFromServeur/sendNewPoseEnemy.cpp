/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** sendNewPoseProjectil
*/

#include "EntityTypes.hpp"
#include "sfServeur.hpp"
#include <SFML/Network.hpp>
//////////////////////////////////////////////////////////////
///@brief send new pose enemy to the client
///@param sfInt16 id for packet send
///@param float x for enemy position
///@param float y for enemy position
///@param sfInt8 live for death system with enemy
///@param sfInt8 type for enemy
//////////////////////////////////////////////////////////////
void sendNewPoseEnemy(sf::Int16 id, float x, float y, sf::Int8 live,
                      sf::Int8 type) noexcept {
  infoServ.sendPacketEntity << id << sf::Int8(enemy_e) << x << y << live
                               << type;
}