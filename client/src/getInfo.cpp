/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** getInfo
*/

#include "EntityTypes.hpp"
#include "Loader.hpp"
#include "RT_Enemy.hpp"
#include "RT_Position.hpp"
#include "Registry.hpp"
#include "commande.hpp"
#include "getEntity.hpp"
#include "sfClient.hpp"

#include <SFML/Network.hpp>
#include <cstring>
#include <iostream>
#include <mutex>

#include <cstdlib>
#include <iostream>

void createEnemyBot(rt::Registry *r, Loader *t, sf::Vector2f pos,
                    sf::Int8 type);
void createProjectile(rt::Registry *r, Loader *t, sf::Vector2f pos);

//////////////////////////////////////////////////////////////
///@brief get projectile information from server
///@param EntityTypes entity type for information
///@param sfPacket received packet from server
///@param int Int for server Port
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
//////////////////////////////////////////////////////////////
void getProjectilInfo(EntityTypes type, sf::Packet &receivedPacket, int id,
                      rt::Registry *r, Loader *t) {
  if (type == projectile_e) {
    float projectil_x = -1;
    float projectil_y = -1;
    pickProjectilArgv(receivedPacket, projectil_x, projectil_y);
    infoFromServ.mut.lock();
    if (r->isEntityCreated(id)) {
      auto &tabPos = r->getComponents<rt::Pos_t>();
      if (tabPos.size() > id && tabPos[id].has_value()) {
        if (projectil_x == -1000 && projectil_y == -1000) {
          r->killEntity(r->entityFromIndex(id));
          return;
        }
        tabPos[id].value().x = projectil_x;
        tabPos[id].value().y = projectil_y;
      }
    } else {
      createProjectile(r, t, sf::Vector2f(projectil_x, projectil_y));
    }
    infoFromServ.mut.unlock();
  }
}

//////////////////////////////////////////////////////////////
///@brief get enemy information from server
///@param EntityTypes entity type for information
///@param sfPacket received packet from server
///@param int Int for server Port
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
//////////////////////////////////////////////////////////////
void getEnemyInfo(EntityTypes type, sf::Packet &receivedPacket, int id,
                  rt::Registry *r, Loader *t) {
  infoFromServ.mut.lock();
  if (type == enemy_e) {
    float x = -1;
    float y = -1;
    sf::Int8 live = -1;
    sf::Int8 type = -1;
    pickEnemyArgv(receivedPacket, x, y, live, type);
    if (r->isEntityCreated(id)) {
      auto &tabPos = r->getComponents<rt::Pos_t>();
      auto &tabEnemy = r->getComponents<rt::EnemyBot>();
      if (tabPos.size() > id && tabPos[id].has_value()) {
        tabPos[id].value().x = x;
        tabPos[id].value().y = y;
        if (tabEnemy.size() > id && tabEnemy[id].has_value()) {
          tabEnemy[id].value().setLive(live);
          if (tabEnemy[id].value().getLive() == 0) {
            tabPos[id].value().x = -1000;
            tabPos[id].value().y = -1000;
          }
        }
      }
    } else {
      createEnemyBot(r, t, sf::Vector2f(x, y), type);
    }
  }
  infoFromServ.mut.unlock();
}