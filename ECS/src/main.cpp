/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** main.cpp
*/

#include "RT_Collision.hpp"
#include "RT_Controllable.hpp"
#include "RT_Drawable.hpp"
#include "RT_Health.hpp"
#include "RT_Hitbox.hpp"
#include "RT_Position.hpp"
#include "RT_Shoots.hpp"
#include "RT_Size.hpp"
#include "RT_parallax.hpp"
#include "Registry.hpp"
#include "Systems.hpp"
#include "sfClient.hpp"
#include "sfServeur.hpp"

#include "Loader.hpp"

#include <algorithm>
#include <thread>

void showGameplay(int port, const char *ip);
void computeGameplay(int port);

int client(int const argc, char const *const *const argv, int port,
           const char *ip) {
  entity initialPos;
  initialPos.x = -1;
  initialPos.y = -1;
  infoFromServ.positions.resize(4);
  // infoFromServ.j = -1;
  std::fill(infoFromServ.positions.begin(), infoFromServ.positions.end(),
            initialPos);
  showGameplay(port, ip);
  return 0;
}

void serveurThread(int port) {
  while (1) {
    ///
  }
}

int serveur(int const argc, char const *const *const argv, int port) {
  // std::thread first(serveurThread, port);
  infoPlayer initialValue;
  initialValue.x = 0;
  initialValue.y = 0;
  initialValue.shoot = 2;
  initialValue.moveX = 0;
  initialValue.moveY = 0;
  initialValue.state = statePlayer::UNKNOW;
  infoServ.players.resize(4);
  std::fill(infoServ.players.begin(), infoServ.players.end(),
            infoPlayer(initialValue));
  computeGameplay(port);
  return (0);
}

int main(int const argc, char const *const *const argv) {
  if (argc == 2)
    serveur(argc, argv, atoi(argv[1]));
  if (argc == 3)
    client(argc, argv, atoi(argv[1]), argv[2]);
  return 0;
}