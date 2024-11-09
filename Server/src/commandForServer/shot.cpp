/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** shot
*/

#include "commande.hpp"
#include "sfServeur.hpp"

#include "EntityTypes.hpp"

#include "iostream"

//////////////////////////////////////////////////////////////
///@brief manage shoot packet sender for server
///@param sfPacket Recovery Packet for data lost
///@param command_e command information for server
///@param sfInt8 index Jx
//////////////////////////////////////////////////////////////
void commandShotForServer(sf::Packet &recoveryPacket, command_e command,
                          sf::Int8 jX) {
  if (command == SHOT) {
    sf::Int8 boolShot = -1;
    recoveryPacket >> boolShot;
    if (boolShot == 1) {
      infoServ.players.at(jX).shoot = 1;
    } else if (boolShot == 2) {
      infoServ.players.at(jX).shoot = 2;
    }
  }
}

void infoShotForClient(sf::Packet &packetToSend, sf::Int8 id, float x, float y,
                       float speed, sf::Int8 type) {
  packetToSend << id << sf::Int8(projectile_e) << x << y << speed << type;
}

//  id, type, a,r,g,u,m,e,n,t