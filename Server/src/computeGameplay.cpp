/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** computeGameplau
*/

#include <SFML/Network.hpp>
#include <thread>

#include "EntityTypes.hpp"
#include "RT_Collision.hpp"
#include "RT_CollisionMulti.hpp"
#include "RT_Controllable.hpp"
#include "RT_Direction.hpp"
#include "RT_Drawable.hpp"
#include "RT_Enemy.hpp"
#include "RT_Health.hpp"
#include "RT_Hitbox.hpp"
#include "RT_Position.hpp"
#include "RT_Shoots.hpp"
#include "RT_ShootsMulti.hpp"
#include "RT_Size.hpp"
#include "RT_Velocity.hpp"
#include "RT_parallax.hpp"
#include "Registry.hpp"
#include "entitySend.hpp"
#include "sfServeur.hpp"

void communication(int port);
void createPlayer(rt::Registry &r, Loader &t, bool control = false,
                  float x = 0, float y = 0);
void initComponents(rt::Registry &r) noexcept;
void updatePlayer(rt::Registry &r);
void updateSendPacketSystem(rt::Registry &r);
void enemyUpdate(rt::Registry &r);
void fireUpdate(rt::Registry &r);
void collitionUpdate(rt::Registry &r);
void makeFire(rt::Registry &r);
void makeEnemy(rt::Registry &r, float x, float y, float c, float moveY,
               float movex, sf::Int8 type, float width, float height,
               int heal = 1000, int shooter = -1);

//////////////////////////////////////////////////////////////
///@brief create and add player to the server
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
///@param size_t size for player list
//////////////////////////////////////////////////////////////
inline void addPlayerIfNeeded(rt::Registry &r, Loader &textures,
                              size_t &nbPlayers) {
  for (size_t i = 0; i < 4 && nbPlayers != 4; i++) {
    statePlayer &actualStatePlayer = infoServ.players.at(i).state;

    if (actualStatePlayer == statePlayer::READY) {
      actualStatePlayer = statePlayer::ALIVE;
      createPlayer(r, textures);
      nbPlayers++;
    }
  }
}

void fileToMapMob(std::string path, rt::Registry &r);

//////////////////////////////////////////////////////////////
///@brief create and add player to the server
///@param int Port for server connection
//////////////////////////////////////////////////////////////
void computeGameplay(int port) {
  rt::Registry r;
  std::thread threadCom(communication, port);
  Loader t;
  size_t nbPlayers = 0;

  sf::Clock clock;

  t.setTextureFromFile("./Assets/Sprites/r-typesheet42.gif", "player");
  initComponents(r);
  bool enemyCree = false;
  while (1) {

    mut.lock();
    addPlayerIfNeeded(r, t, nbPlayers);
    mut.unlock();
    if (clock.getElapsedTime().asMilliseconds() >= (1000 / 60)) {
      if (nbPlayers == 4) {
        mut.lock();
        updatePlayer(r);
        rt::DirectionSystem(r);
        rt::PositionSystem(r);
        updateSendPacketSystem(r);
        makeFire(r);
        if (enemyCree == false) {
          enemyCree = true;
          // make enemy
          fileToMapMob("./map/map0", r);
        }
        fireUpdate(r);
        enemyUpdate(r);
        collitionUpdate(r);
        mut.unlock();
      }
      clock.restart();
    }
  }
  threadCom.join();
}