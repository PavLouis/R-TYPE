/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** createEntity
*/

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
#include "RT_Size.hpp"
#include "RT_Velocity.hpp"
#include "Registry.hpp"
#include "Systems.hpp"
#include "commande.hpp"
#include "parallax.hpp"
#include "sfClient.hpp"

#include "RT_ShootsMulti.hpp"

void createProjectile(rt::Registry *r, Loader *t, sf::Vector2f pos) {
  int oldSize = r->getNbrEntity();
  try {
    Entity mis = r->spawnEntity();
    r->addComponent(mis, rt::Pos_t({pos.x, pos.y}));
    r->addComponent(mis, rt::ShootsMulti());
    r->addComponent(mis, rt::Size_t({20, 20}));
    r->addComponent(
        mis, rt::Drawable(t->get("shoot"), {{0, 0, 20, 20}}, 0, 0, {1, 1}));
  } catch (const std::exception &e) {
    if (oldSize != r->getNbrEntity())
      r->removeEntity();
    std::cerr << e.what() << std::endl;
  }
}

void createEnemyBot(rt::Registry *r, Loader *t, sf::Vector2f pos,
                    sf::Int8 type) {
  std::cout << (int)type << "\n";
  int oldSize = r->getNbrEntity();
  try {
    Entity myEnemy = r->spawnEntity();
    r->addComponent(myEnemy, rt::Pos_t({pos.x, pos.y}));
    r->addComponent(myEnemy, rt::EnemyBot(0, 0, 0));
    r->addComponent(myEnemy, rt::Size_t({4, 4}));
    switch ((int)type) {
    case 0:
      r->addComponent(myEnemy, rt::Drawable(t->get("ground1"),
                                            {{0, 0, 384, 270}}, 0, 0, {1, 1}));
      break;
    case 1:
      r->addComponent(myEnemy, rt::Drawable(t->get("ground2"),
                                            {{0, 0, 384, 40}}, 0, 0, {1, 1}));
      break;
    case 2:
      r->addComponent(myEnemy, rt::Drawable(t->get("ground3"),
                                            {{0, 0, 384, 40}}, 0, 0, {1, 1}));
      break;
    case 3:
      r->addComponent(myEnemy, rt::Drawable(t->get("ground4"),
                                            {{0, 0, 384, 132}}, 0, 0, {1, 1}));
      break;
    case 4:
      r->addComponent(myEnemy, rt::Drawable(t->get("enemy1"), {{{0, 0, 33, 36}, {33, 0, 33, 36}, {66, 0, 33, 36}, {99, 0, 33, 36}}},
                                            150, 0, {1, 1}));
      break;
    case 5:
      r->addComponent(myEnemy, rt::Drawable(t->get("enemy2"), {{{0, 0, 33, 33}, {33, 0, 33, 33}, {66, 0, 33, 33}}},
                                            150, 0, {1, 1}));
      break;
    case 6:
      r->addComponent(myEnemy, rt::Drawable(t->get("enemy3"), {{{0, 0, 33, 33}, {33, 0, 33, 33}, {66, 0, 33, 33}, {99, 0, 33, 33}, {132, 0, 33, 33}, {165, 0, 33, 33}, {198, 0, 33, 33}, {231, 0, 33, 33}}},
                                            150, 0, {1, 1}));
      break;
    case 7:
      r->addComponent(myEnemy,
                      rt::Drawable(t->get("enemyShoot"), {{0, 0, 70, 70}}, 0, 0,
                                   {0.5, 0.5}));
      break;
    case 8:
      r->addComponent(myEnemy, rt::Drawable(t->get("boss1"), {{0, 0, 260, 145}},
                                            0, 0, {1, 1}));
      break;
    default:
      break;
    }
  } catch (const std::exception &e) {
    if (oldSize != r->getNbrEntity())
      r->removeEntity();
    std::cerr << e.what() << std::endl;
  }
}

static void printTest(rt::Registry &r, Entity &mis) {
  std::cout << "TEST\n";
}

void createPlayer(rt::Registry &r, Loader &t, bool control = false,
                  float x = 0, float y = 0) {
  Entity player = r.spawnEntity();
  std::function<void(rt::Registry &, Entity &)> func = printTest;

  std::vector<std::string> c_v;
  c_v.push_back("Wall");
  r.addComponent(player, rt::Collision_t({c_v}));
  r.addComponent(
      player, rt::Drawable(t.get("player"), {{0, 0, 34, 19}}, 0, 0, {1, 1}));
  std::vector<std::string> d_v;
  d_v.push_back("Player");
  r.addComponent(player, rt::Hitbox_t({34, 19}));
  r.addComponent(player, rt::Direction_t({0, 0}));
  r.addComponent(player, rt::Velocity_t({0, 0}));
  r.addComponent(player, rt::Pos_t({x, y}));
  r.addComponent(player, rt::Size_t({34, 19}));
  sf::Vector2f size(1, 1);
  r.addComponent(player, rt::CollisionMulti(size, func));
  if (control) {
    r.addComponent(
        player, rt::Controllable_t({sf::Keyboard::Up, sf::Keyboard::Down,
                                    sf::Keyboard::Left, sf::Keyboard::Right,
                                    sf::Keyboard::Space, sf::Keyboard::E}));
    std::vector<rt::Shoot_t> s_v;
    s_v.push_back({"shoot", {1, 0}, 0.01f, 200, sf::Clock()});
    r.addComponent(player, rt::Shoots_t({s_v}));
  }
}