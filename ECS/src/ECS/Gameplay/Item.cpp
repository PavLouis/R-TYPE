/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Item
*/
#include "Loader.hpp"
#include "RT_Drawable.hpp"
#include "RT_Position.hpp"
#include "Registry.hpp"
#include <iostream>

/**
 * @brief Spawn and draw ItemEntity with position
 * @param r adress of the register from where we will delete the entity
 * @param loader load path for create texture Sprite
 **/
void SpawnItem(rt::Registry &r, Loader &t) {
  static bool state = false;
  auto compPos = r.getComponents<rt::Pos_t>();
  std::size_t idx = 0;
  float x;
  float y;
  std::vector<sf::IntRect> rectItem = {{0, 0, 100, 100}};
  srand(time(0));
  while (idx < compPos.size()) {
    if (compPos[idx].has_value()) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && state == false) {
        x = rand() % 1520;
        y = rand() % 980;
        Entity item1 = r.spawnEntity();
        r.addComponent(item1,
                       rt::Drawable(t.get("item1"), rectItem, sf::Int32(30), 1,
                                    sf::Vector2f(1, 1)));
        r.addComponent(item1, rt::Pos_t({x, y}));
        state = true;
      } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        state = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && idx != 0 && idx)
        r.killEntity((Entity)(idx));
    }
    idx = idx + 1;
  }
}