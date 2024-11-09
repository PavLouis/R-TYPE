/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** EnemyShoot
*/

#include "Registry.hpp"
#include <SFML/Graphics.hpp>

void makeEnemy(rt::Registry &r, float x, float y, float c, float moveY,
               float movex, sf::Int8 type, float width, float height, int heal,
               int shooter);

//////////////////////////////////////////////////////////////
///@brief creation of projectile for enemy
///@param r Registry that store every Components Type
///@param float x for postion enemy
///@param float y for postion enemy
///@param int type of shoot
//////////////////////////////////////////////////////////////
void EnemyShoot(rt::Registry &r, float x, float y, int shoter = 0) {
  makeEnemy(r, x, y, 0, 0, 10, 7, 70 * 0.5, 70 * 0.5, 1000, false);
}

void nothing(rt::Registry &r, float x, float y, int shoter) {}

//////////////////////////////////////////////////////////////
///@brief manage creation of enemy with random value
///@param r Registry that store every Components Type
///@param float x for postion draw
///@param float y for postion draw
///@param int random int for enemy choice
//////////////////////////////////////////////////////////////
void makeRandomEnemy(rt::Registry &r, float x, float y,
                     int type = rand() % 4) {
  switch (type) {
  case 0:
    makeEnemy(r, x, y, -0.002, 0, 2, 4, 35, 35, 3, 3);
    break;
  case 1:
    makeEnemy(r, x, y, -0.3, 0, 1.8, 5, 35, 35, 3, 3);
    break;
  case 2:
    makeEnemy(r, x, y, -0.1, 0, 1.7, 6, 35, 35, 3, 3);
    break;
  case 3:
    makeEnemy(r, 1500, 500, 0, 1, 1, 6, 70 * 0.5, 70 * 0.5, 1, 3);
    break;
  default:
    break;
  }
}