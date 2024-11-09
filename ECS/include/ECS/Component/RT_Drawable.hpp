/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Drawable.hpp
*/


#include <SFML/Graphics.hpp>
#include <vector>

#include "RT_Size.hpp"
#include "RT_Position.hpp"

#pragma once

namespace rt {

    /**
     * @brief Permit to setup Texture to the different sprite and also animation
    */
    class Drawable
    {
    private:
        sf::Vector2f size;
        sf::Sprite sprite;
        sf::Clock clock;
        sf::Int32 frameRate;
        std::vector<sf::IntRect> textureRects;
        std::size_t textureRectIndex;
        unsigned short layer;

    public:
        Drawable() noexcept = default;
        Drawable(Drawable const &) noexcept = default;
        Drawable(Drawable &&) noexcept = default;
        Drawable& operator=(Drawable const &) noexcept = default;
        Drawable& operator=(Drawable &&) noexcept = default;
        ~Drawable() noexcept = default;

        Drawable(sf::Texture const &, std::vector<sf::IntRect> const &, sf::Int32 const &, unsigned short const &layer, sf::Vector2f const &size);
        void updateSpriteTextureRect() noexcept;

        sf::Sprite getSprite() noexcept;
        sf::Time getElapsedTime() const noexcept;
        sf::Int32 getFrameRate() const noexcept;
        unsigned short getLayer() const noexcept;

        void restartClock() noexcept;
        void setSpriteRect(sf::IntRect const &) noexcept;
        void setLayer(unsigned int const) noexcept;
        void setPosition(sf::Vector2i const &) noexcept;
    };

    void DrawableSystem(rt::Registry &, sf::RenderWindow &);

};