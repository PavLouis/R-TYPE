/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_parallax
*/

#include "Registry.hpp"
#include <SFML/Graphics.hpp>

#pragma once
void EnemyShoot(rt::Registry &r, float x, float y, int shoter);
void makeRandomEnemy(rt::Registry &r, float x, float y, int type);
void nothing(rt::Registry &r, float x, float y, int shoter);

namespace rt {

    /**
     * @brief Represent an enemy path and different pattern
    **/
    class EnemyBot
    {
    private:
        bool shooter;
        float cube;
        float yMove;
        float xMove;
        sf::Int8 live;
        sf::Int8 type;
        std::function<void(rt::Registry &r, float x, float y, int sho)> shoot;
        sf::Clock ClockShoot;
        sf::Clock Clock;
    public:
        EnemyBot(float c, float yM, float xM, sf::Int8 t = 0, int s = -1);
        ~EnemyBot() noexcept = default;
        float getCube() const noexcept;
        float getYMove() const noexcept;
        float getXMove() const noexcept;
        sf::Int8 getLive() const noexcept;
        void setLive(sf::Int8 newState) noexcept;
        sf::Int8 getType() const noexcept;
        std::function<void(rt::Registry &r, float x, float y, int sho)> getFctShoot() const;
        sf::Clock getClockShoot() const noexcept;
        void restartClockShoot() noexcept;
        sf::Clock getClock() const noexcept;
        void restartClock() noexcept;
    };
}


