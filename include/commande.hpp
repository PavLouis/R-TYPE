/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** commande
*/

#pragma once

#include <SFML/Network/Packet.hpp>

//////////////////////////////////////////////////////////////
///@brief Represent all the commands the client can send to the server to
///communicate with him.
//////////////////////////////////////////////////////////////
enum command_e { END = -1, MOVE = 124, SHOT = 1 };

void clearCommunication() noexcept;
void move(float x, float y) noexcept;
void shot(sf::Int8 shotBool) noexcept;
