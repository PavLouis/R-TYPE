/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** test
*/

#include "Registry.hpp"
#include <SFML/Network.hpp>
#include <fstream>
#include <iostream>
#include <vector>

void makeEnemy(rt::Registry &r, float x, float y, float c, float moveY,
               float movex, sf::Int8 type, float width, float height, int heal,
               int shooter);

std::vector<std::string> GetTokenTab(std::string info) {
  std::string delimiter = ", ";
  size_t pos = 0;
  std::string token;
  std::vector<std::string> tokenTab;

  while ((pos = info.find(delimiter)) != std::string::npos) {
    token = info.substr(0, pos);
    tokenTab.push_back(token);
    std::cout << token << std::endl;
    info.erase(0, pos + delimiter.length());
  }
  tokenTab.push_back(info);
  std::cout << info << std::endl;
  std::cout << "token size = " << tokenTab.size() << "\n";
  return tokenTab;
}

//////////////////////////////////////////////////////////////
///@brief manage call to enemy Creation
///@param stdstring string path
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
void fileToMapMob(std::string path, rt::Registry &r) {
  std::ifstream file(path);
  float x = -1;
  float y = -1;
  float c = -1;
  float moveY = -1;
  float movex = -1;
  int type = -1;
  float width = -1;
  float height = -1;
  int heal = -1;
  int shooter = -1;
  std::vector<std::string> tokenTab;

  if (file) {
    std::string ligne;
    while (getline(file, ligne)) {
      tokenTab = GetTokenTab(ligne);
      if (tokenTab.size() == 10) {
        makeEnemy(r, std::stof(tokenTab[0]), std::stof(tokenTab[1]),
                  std::stof(tokenTab[2]), std::stof(tokenTab[3]),
                  std::stof(tokenTab[4]), std::stof(tokenTab[5]),
                  std::stof(tokenTab[6]), std::stof(tokenTab[7]),
                  std::stoi(tokenTab[8]), std::stoi(tokenTab[9]));
      } else {
        std::cerr << "error tokenTab.size() = " << tokenTab.size() << "\n";
      }
    }
  } else {
    throw std::logic_error(
        "ERREUR: Impossible d'ouvrir le fichier en lecture.");
  }
}