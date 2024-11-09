/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** parallax
*/

#pragma once

#include "Registry.hpp"
#include <memory>
#include <SFML/Graphics.hpp>
#include "Loader.hpp"
//////////////////////////////////////////////////////////////
///@brief Parallax classe for parallax management
//////////////////////////////////////////////////////////////
class parallax
{
private:
    float posX;
    float posX2;
    float starPosX;
    float starPosX2;
    bool state;
    int opacity;

    sf::Clock clock;

    sf::Texture texture1;
    sf::Texture texture2;

    sf::Texture textureStarStage1;

    sf::Sprite spriteStarStageOne1;
    sf::Sprite spriteStarStageOne2;

    sf::Sprite back1;
    sf::Sprite back2;
    sf::RectangleShape blackRectangle;    
public:
    parallax() noexcept;
    ~parallax() noexcept = default;
    void parallaxManage(sf::RenderWindow &window,  int blackBack, int mecaBack);
    void position() noexcept;
    void respawn() noexcept;
};

void SpawnItem(rt::Registry &r, Loader &t);
