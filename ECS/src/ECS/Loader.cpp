/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Loader
*/

#include "Loader.hpp"

void Loader::setTextureFromFile(const std::string texturePath,
                                std::string name) {
  if (name.empty()) {
    this->holderTexture[texturePath] = std::make_unique<sf::Texture>();
    this->holderTexture[texturePath].get()->loadFromFile(texturePath);
  } else {
    this->holderTexture[name] = std::make_unique<sf::Texture>();
    this->holderTexture[name].get()->loadFromFile(texturePath);
  }
}

sf::Texture &Loader::get(std::string str) const noexcept{
  return *this->holderTexture.at(str).get();
}
