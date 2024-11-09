/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** SoundSysteme
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "RT_Sound.hpp"
#include "Registry.hpp"

void rt::SoundSystem(rt::Registry &r) {
  std::string path = "./Assets/Sprites/sound1.wav";
  auto &tabSound = r.getComponents<rt::Sound_t>();
  std::size_t idx = 0;
  while (idx < tabSound.size()) {
    auto &compSound = tabSound[idx];
    if (tabSound[idx].has_value()) {
      if (!compSound.value().buffer2.loadFromFile(path) ||
          !compSound.value().buffer1.loadFromFile(path) ||
          !compSound.value().buffer3.loadFromFile(path))
        ;
      compSound.value().sound1.setBuffer(compSound.value().buffer1);
      compSound.value().sound2.setBuffer(compSound.value().buffer2);
      compSound.value().sound3.setBuffer(compSound.value().buffer3);
      compSound.value().sound1.setVolume(70.0);
      compSound.value().sound2.setVolume(70.0);
      compSound.value().sound3.setVolume(70.0);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        std::cout << "kk" << std::endl;
        compSound.value().sound1.play();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        std::cout << "kk2" << std::endl;
        compSound.value().sound2.play();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        std::cout << "kk3" << std::endl;
        compSound.value().sound3.play();
      }
    }
    idx = idx + 1;
  }
}