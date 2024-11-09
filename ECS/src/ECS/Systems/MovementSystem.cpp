/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** DirectionSystem.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "RT_Collision.hpp"
#include "RT_Controllable.hpp"
#include "RT_Direction.hpp"
#include "RT_Drawable.hpp"
#include "RT_Health.hpp"
#include "RT_Hitbox.hpp"
#include "RT_Position.hpp"
#include "RT_Size.hpp"
#include "RT_Velocity.hpp"
#include "Registry.hpp"

//////////////////////////////////////////////////////////////
///@brief Direction System : Change the velocity from velocity parameter
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void rt::DirectionSystem(rt::Registry &r) {
  auto &tabDirections = r.getComponents<rt::Direction_t>();
  auto &tabVelocities = r.getComponents<rt::Velocity_t>();
  std::size_t idx = 0;

  while (idx < tabDirections.size() && idx < tabVelocities.size()) {
    auto &compDirection = tabDirections[idx];
    auto &compVelocity = tabVelocities[idx];
    if (tabDirections[idx].has_value() && tabVelocities[idx].has_value()) {
      if (compDirection.value().x == 1)
        compVelocity.value().x = 2;
      else if (compDirection.value().x == -1)
        compVelocity.value().x = -2;
      else
        compVelocity.value().x = 0;

      if (compDirection.value().y == -1)
        compVelocity.value().y = -2;
      else if (compDirection.value().y == 1)
        compVelocity.value().y = 2;
      else
        compVelocity.value().y = 0;
    }
    idx = idx + 1;
  }
}