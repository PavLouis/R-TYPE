/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** sfServeur
*/

#pragma once

#include <SFML/Network/Packet.hpp>
#include <mutex>
#include <vector>

#define NB_MAX_PLAYERS 4

enum class statePlayer { UNKNOW, READY, ALIVE, DEAD };

struct infoPlayer {
  float x;
  float y;
  sf::Int8 shoot;
  float moveX;
  float moveY;
  statePlayer state;
};

struct sfServCom {
  sf::Packet sendPacket;
  sf::Packet sendPacketEntity;
  std::mutex mutEntity;
  std::vector<infoPlayer> players;
};

inline std::mutex mut;
inline sfServCom infoServ;
