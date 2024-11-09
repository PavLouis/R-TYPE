/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** makeSpecialEntity
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

inline void printTest(rt::Registry &r, Entity &mis) {
  std::cout << "TEST\n";
}

//////////////////////////////////////////////////////////////
///@brief creation of fire entity for Player and enemy
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void makeFire(rt::Registry &r) {
  std::function<void(rt::Registry &, Entity &)> func = printTest;

  for (int i = 0; i < 4; i += 1) {
    if (infoServ.players.at(i).shoot == 1) {
      infoServ.players.at(i).shoot = 0;
      Entity mis = r.spawnEntity();
      r.addComponent(mis, rt::ShootsMulti());
      sf::Vector2f size(20 * 4, 20 * 4);
      r.addComponent(
          mis, rt::CollisionMulti(size, func));
      r.addComponent(
          mis, rt::Pos_t{infoServ.players.at(i).x, infoServ.players.at(i).y});
      std::cout << i
                << "Je crée le tire dans le serveur sur la pos du joueur\n";
    }
  }
}

//////////////////////////////////////////////////////////////
///@brief enemy Creation
///@param r Registry that store every Components Type
///@param float x point for entity spawn position
///@param float y point for entity spawn position
///@param float c point for entity spawn position
///@param float moveX coordonate point for entity movement
///@param float moveY coordonate point for entity movement
///@param sfInt8 type enemy type
///@param float width of entity
///@param float height of entity
///@param int heal number of heal point for entity
///@param int shooter type for shoot
//////////////////////////////////////////////////////////////
void makeEnemy(rt::Registry &r, float x, float y, float c, float moveY,
               float movex, sf::Int8 type, float width, float height,
               int heal = 1000, int shooter = -1) {
  std::function<void(rt::Registry &, Entity &)> func = printTest;

  Entity mis = r.spawnEntity();
  r.addComponent(mis, rt::EnemyBot(c, moveY, movex, type, shooter));
  sf::Vector2f size(width, height);
  r.addComponent(mis,
                    rt::CollisionMulti(size, func));
  r.addComponent(mis, rt::Pos_t{x, y});
  r.addComponent(mis, rt::Health_t{heal});
  std::cout << "enemy creates\n";
}
