/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** sendNewPoseProjectil
*/

#include "EntityTypes.hpp"
#include "sfServeur.hpp"
#include <SFML/Network.hpp>
#include <iostream>

//////////////////////////////////////////////////////////////
///@brief send new pose projectile to the client
///@param sfInt16 id for packet send
///@param float x for projectile position
///@param float y for projectile position
//////////////////////////////////////////////////////////////
void sendNewPoseProjectil(sf::Int16 id, float x, float y) noexcept {
  //    if (x < 2000)
  //        std::cout << "HOOOO NOOOOO\n";
  infoServ.sendPacketEntity << id << sf::Int8(projectile_e) << x << y;
}