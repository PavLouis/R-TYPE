/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Loader
*/

#pragma once

#include <memory>
#include <map>
#include <SFML/Graphics/Texture.hpp>

/**
 * @brief Handle all the textures, load and unload.
**/
class Loader {
    public:
        Loader() noexcept = default;
        ~Loader() noexcept = default;
        /**
         * @brief Will load the texture given and will stock it in a pointer.
         *  If a name is given it will be the key and if you don't have given a name the key will be the path.
         * @param texturePath path of your texture to  load
         * @param name the name of the key to get the texture
        **/
        void setTextureFromFile(const std::string texturePath, std::string name = "");

        /**
         * @brief Get the adress of the texture but the texture need to be already loaded with the function setTextureFromFile.
         * @param key permit you to access the texture with the key
         * @return address Read/Write of the texture
         * @throw If key don't exist throw std::out_of_range
        **/
        sf::Texture &get(std::string key) const noexcept;

    private:
        std::map<std::string, std::unique_ptr<sf::Texture>> holderTexture;
};
