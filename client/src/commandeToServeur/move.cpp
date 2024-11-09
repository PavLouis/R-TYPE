/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** move
*/

#include "commande.hpp"
#include "sfClient.hpp"

void move(float x, float y) noexcept {
  infoFromServ.packetForServ << sf::Int8(MOVE) << x << y;
}