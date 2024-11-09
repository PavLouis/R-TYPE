/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** move
*/

#include "commande.hpp"
#include "sfServeur.hpp"

//////////////////////////////////////////////////////////////
///@brief manage move packet sender for server
///@param sfPacket Recovery Packet for data lost
///@param command_e command information for server
///@param sfInt8 index Jx
//////////////////////////////////////////////////////////////
void commandMoveForServer(sf::Packet &recoveryPacket, command_e command,
                          sf::Int8 jX) {
  if (command == MOVE) {
    float moveX = -1;
    float moveY = -1;
    recoveryPacket >> moveX >> moveY;
    infoServ.players.at(jX).moveX = moveX;
    infoServ.players.at(jX).moveY = moveY;
  }
}
