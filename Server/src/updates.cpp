/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** updates
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

//////////////////////////////////////////////////////////////
///@brief Update Player position for server
/// @param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void updatePlayer(rt::Registry &r) {
  auto &tabDirections = r.getComponents<rt::Direction_t>();

  for (size_t i = 0; i < NB_MAX_PLAYERS; i++) {
    auto &playerX = tabDirections[i];
    if (playerX.has_value()) {
      playerX.value().x = infoServ.players.at(i).moveX;
      playerX.value().y = infoServ.players.at(i).moveY;
    }
  }
}

//////////////////////////////////////////////////////////////
///@brief Update SendPackect system
/// @param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void updateSendPacketSystem(rt::Registry &r) {
  const auto &compPos = r.getComponents<rt::Pos_t>();

  // Update position for the player
  for (size_t i = 0; i < NB_MAX_PLAYERS; i++) {
    const auto &pos = compPos[i];
    if (pos.has_value()) {
      infoServ.players.at(i).x = pos.value().x;
      infoServ.players.at(i).y = pos.value().y;
      // std::cerr << "[" << i << "]: x = " << infoServ.players.at(i).x << " y =
      // " << infoServ.players.at(i).y << std::endl;
    }
  }
}

//////////////////////////////////////////////////////////////
///@brief Update Enemy Event and position
/// @param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void enemyUpdate(rt::Registry &r) {
  auto &tabEnemy = r.getComponents<rt::EnemyBot>();
  auto &tabEnemyPos = r.getComponents<rt::Pos_t>();

  for (size_t i = 0; i < tabEnemy.size(); i++) {
    if (tabEnemy[i].has_value() && tabEnemyPos[i].has_value()) {
      infoServ.mutEntity.lock();
      if (tabEnemyPos[i].value().x < 1500) {
        tabEnemyPos[i].value().x -= tabEnemy[i].value().getXMove();
        tabEnemyPos[i].value().y -=
            (tabEnemy[i].value().getYMove() +
             (tabEnemy[i].value().getClock().getElapsedTime().asMilliseconds() /
              100) *
                 tabEnemy[i].value().getCube());
        if (tabEnemy[i].value().getClockShoot().getElapsedTime().asSeconds() >
                1 &&
            tabEnemy[i].value().getLive() == 1) {
          tabEnemy[i].value().getFctShoot()(r, tabEnemyPos[i].value().x,
                                            tabEnemyPos[i].value().y,
                                            rand() % 4);
          tabEnemy[i].value().restartClockShoot();
        }
      } else {
        tabEnemyPos[i].value().x -= 1;
        tabEnemy[i].value().restartClock();
      }
      sendNewPoseEnemy(sf::Int16(i), tabEnemyPos[i].value().x,
                       tabEnemyPos[i].value().y, tabEnemy[i].value().getLive(),
                       tabEnemy[i].value().getType());
      infoServ.mutEntity.unlock();
    }
  }
}

//////////////////////////////////////////////////////////////
///@brief Update FireSystem for player information
/// @param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void fireUpdate(rt::Registry &r) {
  auto &tabShoot = r.getComponents<rt::ShootsMulti>();
  auto &tabPos = r.getComponents<rt::Pos_t>();
  sf::Clock yes;

  for (size_t i = 0; i < tabShoot.size(); i++) {
    if (tabShoot[i].has_value()) {
      infoServ.mutEntity.lock();
      tabPos[i].value().x +=
          tabShoot[i].value().getClock().getElapsedTime().asMilliseconds();
      tabShoot[i].value().restartClock();
      sendNewPoseProjectil(sf::Int16(i), tabPos[i].value().x,
                           tabPos[i].value().y);
      infoServ.mutEntity.unlock();
    }
  }
}

//////////////////////////////////////////////////////////////
///@brief Update Collition with entity
/// @param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void collitionUpdate(rt::Registry &r) {
  auto &tabColition = r.getComponents<rt::CollisionMulti>();
  auto &tabEnemy = r.getComponents<rt::EnemyBot>();
  auto &tabShoot = r.getComponents<rt::ShootsMulti>();
  auto &tabPos = r.getComponents<rt::Pos_t>();
  auto &tabHeal = r.getComponents<rt::Health_t>();
  // Rect

  for (size_t i = 0; i < tabColition.size() && i < tabPos.size(); i++) {
    if (tabColition[i].has_value() && tabPos[i].has_value()) {
      infoServ.mutEntity.lock();
      for (size_t j = 0; j < tabColition.size() && j < tabPos.size(); j++) {
        if (tabColition[j].has_value() && tabPos[j].has_value() && i != j) {
          int jLeft = tabPos[j].value().x;
          int iLeft = tabPos[i].value().x;
          int iRight = tabPos[i].value().x + tabColition[i].value().getRect().x;
          if (jLeft >= iLeft && jLeft <= iRight) {
            int jTop = tabPos[j].value().y;
            int iTop = tabPos[i].value().y;
            int iBot = tabPos[i].value().y + tabColition[i].value().getRect().y;
            if (iTop <= jTop && jTop <= iBot) {
              if (tabEnemy.size() > i && tabEnemy[i].has_value()) {
                if (j < 4) {
                  r.killEntity(r.entityFromIndex(j));
                }
                if (tabShoot.size() > j && tabShoot[j].has_value()) {
                  if (tabHeal.size() > i && tabEnemy[i].has_value())
                    if (tabHeal[i].value().health < 0) {
                      tabEnemy[i].value().setLive(0);
                      tabPos[i].value().y = -1000;
                      tabPos[i].value().x = -1000;
                    } else {
                      tabHeal[i].value().health -= 1;
                    }
                  Entity entity(i);
                  tabColition[j].value().setCollision(true);
                  tabColition[j].value().getFuncInCollision()(r, entity);
                }
              }
            }
          }
        }
      }
      infoServ.mutEntity.unlock();
    }
  }
  for (size_t i = 0; i < tabColition.size(); i++) {
    if (tabColition[i].has_value()) {
      if (tabColition[i].value().getCollision() == true) {
        auto &tabPos = r.getComponents<rt::Pos_t>();
        if (tabPos[i].has_value()) {
          tabPos[i].value().x = -1000;
          tabPos[i].value().y = -1000;
          // r.killEntity(r.entityFromIndex(i));
        }
      }
    }
  }
}