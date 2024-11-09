/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** showGameplay
*/

#include "RT_Collision.hpp"
#include "RT_CollisionMulti.hpp"
#include "RT_Controllable.hpp"
#include "RT_Direction.hpp"
#include "RT_Drawable.hpp"
#include "RT_Enemy.hpp"
#include "RT_Health.hpp"
#include "RT_Hitbox.hpp"
#include "RT_Position.hpp"
#include "RT_Shoots.hpp"
#include "RT_Size.hpp"
#include "RT_Music.hpp"
#include "RT_Velocity.hpp"
#include "Registry.hpp"
#include "Systems.hpp"
#include "commande.hpp"
#include "parallax.hpp"
#include "sfClient.hpp"

#include "RT_ShootsMulti.hpp"

#include <thread>

void initComponents(rt::Registry &r) noexcept;
void communicationServ(int port, const char *ip, rt::Registry *r, Loader *t);
void createPlayer(rt::Registry &r, Loader &t, bool control = false,
                  float x = 0, float y = 0);
void createEnemyBot(rt::Registry *r, Loader *t, sf::Vector2f pos,
                    sf::Int8 type);
void createProjectile(rt::Registry *r, Loader *t, sf::Vector2f pos);

//////////////////////////////////////////////////////////////
///@brief fill packet system
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
inline void fillPacketSystem(rt::Registry &r) {
  auto compCtrl = r.getComponents<rt::Controllable_t>();
  auto tabDirections = r.getComponents<rt::Direction_t>();

  clearCommunication();
  for (size_t i = 0; i < compCtrl.size() && i < tabDirections.size(); i++) {
    auto &ctrl = compCtrl[i];
    auto &direction = tabDirections[i];
    if (ctrl.has_value() && direction.has_value()) {
      move(direction.value().x, direction.value().y);
      shot(sf::Int8(infoFromServ.shot));
    }
  }
  infoFromServ.packetForServ << sf::Int8(END);
}

//////////////////////////////////////////////////////////////
///@brief update entity system for client
///@param r Registry that store every Components Type
//////////////////////////////////////////////////////////////
inline void updateEntitySystem(rt::Registry &r) {
  auto &compPos = r.getComponents<rt::Pos_t>();

  for (size_t i = 0; i < 4; i++) {
    auto &entity = compPos[i];
    if (entity.has_value()) {
      entity.value().x = infoFromServ.positions.at(i).x;
      entity.value().y = infoFromServ.positions.at(i).y;
    }
  }
}

inline void setupMusic(rt::Registry &r)
{
  r.addComponent<rt::Music_t>(r.entityFromIndex(0), rt::Music_t());
}

//////////////////////////////////////////////////////////////
///@brief main loop for gameplay
///@param window Window for Sfml content
///@param r Registry that store every Components Type
///@param sfClock clock for main loop
///@param Loader loader for texture load from file
///@param parallax parallax class
//////////////////////////////////////////////////////////////
inline void gameplayLoop(sf::RenderWindow &window, sf::Clock &clock,
                         rt::Registry &r, Loader &t, parallax &para) {
  setupMusic(r);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    if (clock.getElapsedTime().asMilliseconds() >= (1000 / 60)) {
      infoFromServ.mut.lock();
      updateEntitySystem(r);
      rt::shootMultiPlayerSysteme(r);
      rt::ControllableSystem(r, t);
      rt::DirectionSystem(r);
      rt::PositionSystem(r);
      rt::MusicSystem(r);
      para.parallaxManage(window, 5000, 20000);
      rt::DrawableSystem(r, window);
      infoFromServ.mut.unlock();
      clock.restart();
    }
    infoFromServ.mut.lock();
    fillPacketSystem(r);
    infoFromServ.mut.unlock();
  }
}

//////////////////////////////////////////////////////////////
///@brief show gameplay for player
///@param int int for server Port
///@param int ip for server connection
//////////////////////////////////////////////////////////////
void showGameplay(int port, const char *ip) {
  rt::Registry r;
  bool playerCreated = false;
  parallax para;

  initComponents(r);
  Loader t;
  t.setTextureFromFile("./Assets/Sprites/r-typesheet42.gif", "player");
  t.setTextureFromFile("./Assets/Sprites/r-typesheet3.gif", "shoot");
  t.setTextureFromFile("./Assets/Sprites/r-typesheet5.gif", "enemy1");
  t.setTextureFromFile("./Assets/Sprites/r-typesheet7.gif", "enemy2");
  t.setTextureFromFile("./Assets/Sprites/r-typesheet8.gif", "enemy3");
  t.setTextureFromFile("./Assets/Sprites/r-typesheet30a.gif", "enemyShoot");
  t.setTextureFromFile("./Assets/Sprites/r-typesheet36.gif", "boss1");
  t.setTextureFromFile("./Assets/Sprites/ground1.png", "ground1");
  t.setTextureFromFile("./Assets/Sprites/ground2.png", "ground2");
  t.setTextureFromFile("./Assets/Sprites/ground3.png", "ground3");
  t.setTextureFromFile("./Assets/Sprites/ground4.png", "ground4");

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
  sf::Clock clock;

  std::thread threadCom(communicationServ, port, ip, &r, &t);
  while (!playerCreated) {
    if (!playerCreated && infoFromServ.j >= 1) {
      // std::cerr << "YOU are j = " << int(infoFromServ.j) << std::endl;
      for (int i = 0; i < 4; i++) {
        infoFromServ.mut.lock();
        if (i == (int)(infoFromServ.j - 1)) {
          createPlayer(r, t, true, 20 * (float)i, 20 * (float)i);
        } else {
          createPlayer(r, t, false, 20 * (float)i, 20 * (float)i);
        }
        infoFromServ.mut.unlock();
      }
      playerCreated = true;
    }
  }
  gameplayLoop(window, clock, r, t, para);
  threadCom.join();
}