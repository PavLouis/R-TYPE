/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** ControllableSystem.cpp
*/

#include "commande.hpp"
#include <SFML/Graphics.hpp>

#include "Loader.hpp"
#include "RT_Controllable.hpp"
#include "RT_Direction.hpp"
#include "RT_Drawable.hpp"
#include "RT_Shoots.hpp"
#include "Registry.hpp"

//////////////////////////////////////////////////////////////
///@brief Draw parallax sprite and manage transition events
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
//////////////////////////////////////////////////////////////
void rt::ControllableSystem(rt::Registry &r, Loader &t) {
  auto compCtrl = r.getComponents<rt::Controllable_t>();
  auto &tabDirection = r.getComponents<rt::Direction_t>();
  auto compPos = r.getComponents<rt::Pos_t>();
  auto &compShoots = r.getComponents<rt::Shoots_t>();
  std::size_t idx = 0;

  while (idx < compCtrl.size() && idx < tabDirection.size()) {
    auto &compDirection = tabDirection[idx];
    if (compCtrl[idx].has_value()) {
      if (sf::Keyboard::isKeyPressed(compCtrl[idx].value().downKey))
        compDirection.value().y = 1;
      else if (sf::Keyboard::isKeyPressed(compCtrl[idx].value().upKey))
        compDirection.value().y = -1;
      else
        compDirection.value().y = 0;
      if (sf::Keyboard::isKeyPressed(compCtrl[idx].value().leftKey))
        compDirection.value().x = -1;
      else if (sf::Keyboard::isKeyPressed(compCtrl[idx].value().rightKey))
        compDirection.value().x = 1;
      else
        compDirection.value().x = 0;
    }
    idx = idx + 1;
  }
}