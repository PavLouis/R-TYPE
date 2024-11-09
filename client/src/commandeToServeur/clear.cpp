/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** clear
*/

#include "sfClient.hpp"

void clearCommunication() noexcept {
  infoFromServ.packetForServ.clear();
  infoFromServ.packetForServ << infoFromServ.j;
}