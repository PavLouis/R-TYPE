/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Enemy
*/

#include "RT_Enemy.hpp"

rt::EnemyBot::EnemyBot(float c, float yM, float xM, sf::Int8 t, int s) {
  shooter = s;
  switch (s) {
  case 0:
    shoot = nothing;
    break;
  case 1:
    shoot = makeRandomEnemy;
    break;
  case 3:
    shoot = EnemyShoot;
    break;
  default:
    shoot = EnemyShoot;
    break;
  }
  type = t;
  cube = c;
  yMove = yM;
  xMove = xM;
  live = 1;
  Clock.restart();
}

float rt::EnemyBot::getCube() const noexcept { return this->cube; }

float rt::EnemyBot::getXMove() const noexcept { return this->xMove; }

float rt::EnemyBot::getYMove() const noexcept { return this->yMove; }

sf::Int8 rt::EnemyBot::getLive() const noexcept { return this->live; }

void rt::EnemyBot::setLive(sf::Int8 newState) noexcept { this->live = newState; }

sf::Int8 rt::EnemyBot::getType() const noexcept { return this->type; }

std::function<void(rt::Registry &r, float x, float y, int sho)>
rt::EnemyBot::getFctShoot() const {
  return this->shoot;
}

sf::Clock rt::EnemyBot::getClockShoot() const noexcept { return this->ClockShoot; }

void rt::EnemyBot::restartClockShoot() noexcept { this->ClockShoot.restart(); }

sf::Clock rt::EnemyBot::getClock() const noexcept { return this->Clock; }

void rt::EnemyBot::restartClock() noexcept { this->Clock.restart(); }
