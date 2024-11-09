/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** MusicSystem
*/

#include <SFML/Audio.hpp>

#include "RT_Music.hpp"
#include "RT_Position.hpp"
#include "Registry.hpp"

//////////////////////////////////////////////////////////////
///@brief Manage MusicSystem, change music back with event
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void rt::MusicSystem(rt::Registry &r) {
  std::string path = "./Assets/Sprites/music.wav";
  std::string path2 = "./Assets/Sprites/music2.wav";
  static sf::Clock clock;
  auto &tabPos = r.getComponents<rt::Pos_t>();
  auto &tabMusic = r.getComponents<rt::Music_t>();
  std::size_t idx = 0;
  while (idx < tabMusic.size() && idx < tabPos.size()) {
    auto &compMusic = tabMusic[idx];
    auto &compPos = tabPos[idx];
    std::cout << compMusic.value().volume2 << std::endl;
    if (tabMusic[idx].has_value() && tabPos[idx].has_value()) {
      compMusic.value().Music.setVolume(compMusic.value().volume);
      compMusic.value().Music2.setVolume(compMusic.value().volume2);
      if (compMusic.value().state != true) {
        if (!compMusic.value().buffer.loadFromFile(path))
          ;
        if (!compMusic.value().buffer2.loadFromFile(path2))
          ;
        compMusic.value().Music.setBuffer(compMusic.value().buffer);
        compMusic.value().Music2.setBuffer(compMusic.value().buffer2);
        compMusic.value().Music.setLoop(true);
        compMusic.value().Music2.setLoop(true);
        compMusic.value().Music.play();
        compMusic.value().Music2.play();
        compMusic.value().state = true;
      }
      if (clock.getElapsedTime().asSeconds() > 15 && compMusic.value().volume >= 1) {
        compMusic.value().volume = compMusic.value().volume - 0.05;
      } else if (compMusic.value().volume <= 1 &&
                 compMusic.value().volume2 <= 40.0) {
        compMusic.value().volume = 0;
        compMusic.value().volume2 = compMusic.value().volume2 + 0.05;
      }
    }
    idx = idx + 1;
  }
}