/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** commande
*/

#pragma once
#include <SFML/Network/Packet.hpp>

//////////////////////////////////////////////////////////////
///@brief Represent all types of Entity the server can send to the client to
///communicate with him. Its not set not class enum because we need to be able to
///declare them explicitly.
//////////////////////////////////////////////////////////////
enum EntityTypes { Player_e = 0, projectile_e = 1, enemy_e = 5, kill = 7 };
