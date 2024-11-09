/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** DrawableSystem.cpp
*/

#include "RT_Drawable.hpp"
#include "Registry.hpp"

//////////////////////////////////////////////////////////////
///@brief Drawable system for sprite management
///@param r Registry that store every Components Type
///@param window Window for Sfml content
//////////////////////////////////////////////////////////////
void rt::DrawableSystem(rt::Registry &r, sf::RenderWindow &window) {
  auto &compDraw = r.getComponents<rt::Drawable>();
  auto compPos = r.getComponents<rt::Pos_t>();
  std::size_t idx = 0;
  unsigned int layer = 0;

  while (layer < 10) {
    while (idx < compDraw.size() && idx < compPos.size()) {
      if (compDraw[idx].has_value() && compPos[idx].has_value() &&
          compDraw[idx].value().getLayer() == layer) {
        compDraw[idx].value().updateSpriteTextureRect();
        compDraw[idx].value().setPosition(
            {static_cast<int>(compPos[idx].value().x),
             static_cast<int>(compPos[idx].value().y)});
        window.draw(compDraw[idx].value().getSprite());
      }
      idx = idx + 1;
    }
    idx = 0;
    layer = layer + 1;
  }
  window.display();
}