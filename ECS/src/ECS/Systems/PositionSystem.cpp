/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** PositionSystem.cpp
*/

#include "RT_Position.hpp"
#include "RT_Velocity.hpp"
#include "Registry.hpp"

//////////////////////////////////////////////////////////////
/// @brief Position System
/// @param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void rt::PositionSystem(rt::Registry &r) {
  auto &compPos = r.getComponents<rt::Pos_t>();
  auto compMov = r.getComponents<rt::Velocity_t>();
  std::size_t idx = 0;

  while (idx < compPos.size() && idx < compMov.size()) {
    if (compPos[idx].has_value() && compMov[idx].has_value()) {
      compPos[idx].value().x = compPos[idx].value().x + compMov[idx].value().x;
      compPos[idx].value().y = compPos[idx].value().y + compMov[idx].value().y;
    }
    idx = idx + 1;
  }
}