/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** shot
*/

#include "commande.hpp"
#include "sfClient.hpp"

#include "iostream"

void shot(sf::Int8 shotBool) noexcept {
  infoFromServ.packetForServ << sf::Int8(SHOT) << shotBool;
}