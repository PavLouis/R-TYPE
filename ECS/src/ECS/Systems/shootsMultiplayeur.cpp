/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** ParallaxSysteme
*/

#include "RT_ShootsMulti.hpp"
#include "Registry.hpp"
#include "sfClient.hpp"

//////////////////////////////////////////////////////////////
///@brief init shoot system if space key is pressed
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void rt::shootMultiPlayerSysteme(rt::Registry &r) {
  auto &tabShoot = r.getComponents<rt::ShootsMulti>();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    infoFromServ.shot = 1;
  } else {
    infoFromServ.shot = 2;
  }
}