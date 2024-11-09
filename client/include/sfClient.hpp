/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** sfClient
*/

#pragma once

#include "Loader.hpp"
#include "Registry.hpp"
#include <SFML/Network.hpp>
#include <mutex>

#define BUFFER_SIZE 1024

struct entity {
  float x;
  float y;
};

struct sfClientCom {
  std::mutex mut;
  sf::Packet packetForServ;
  sf::Int8 j;
  sf::Int8 shot = 2;
  std::vector<entity> positions;
};

inline sfClientCom infoFromServ;

class ClientCom {
public:
  ClientCom() noexcept = default;
  ~ClientCom() noexcept = default;
  int connectionTCP(const sf::IpAddress &remoteAddress, unsigned short port);
  int communicationUDP(std::string IP, unsigned short port, sf::Int8 jx,
                     rt::Registry *r, Loader *t);

protected:
private:
};