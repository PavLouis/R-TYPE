/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** parallax
*/

#include "parallax.hpp"

//////////////////////////////////////////////////////////////
///@brief Parallax constructor's, Set Sprite and texture with position
//////////////////////////////////////////////////////////////
parallax::parallax() noexcept {
  this->opacity = 0;
  this->blackRectangle.setSize(sf::Vector2f(1920, 1080));
  this->blackRectangle.setFillColor(sf::Color(0, 0, 0, this->opacity));
  this->state = false;
  this->clock.restart();
  this->posX = 0.0;
  this->posX2 = 2000.0;
  this->starPosX = 0.0;
  this->starPosX2 = 1920.0;
  sf::String starPath = "./Assets/Sprites/star-field.gif";
  sf::String path = "./Assets/Sprites/star-back.gif";
  sf::String path2 = "./Assets/Sprites/mecaBack.gif";
  if (!this->texture1.loadFromFile(path))
    ;
  if (!this->texture2.loadFromFile(path2))
    ;
  if (!this->textureStarStage1.loadFromFile(starPath))
    ;
  this->back1.setTexture(this->texture1);
  this->back2.setTexture(this->texture1);
  this->spriteStarStageOne1.setTexture(this->textureStarStage1);
  this->spriteStarStageOne2.setTexture(this->textureStarStage1);
  this->spriteStarStageOne1.setColor(sf::Color(255, 255, 255, 70));
  this->spriteStarStageOne2.setColor(sf::Color(255, 255, 255, 70));
}

//////////////////////////////////////////////////////////////
///@brief Incremente and update position for the parallax background
//////////////////////////////////////////////////////////////
void parallax::position() noexcept {
  this->back1.setPosition(this->posX, 0);
  this->back2.setPosition(this->posX2, 0);
  this->spriteStarStageOne1.setPosition(this->starPosX, 0);
  this->spriteStarStageOne2.setPosition(this->starPosX2, 0);
  this->posX -= 2;
  this->posX2 -= 2;
  this->starPosX -= 3;
  this->starPosX2 -= 3;
}

//////////////////////////////////////////////////////////////
///@brief Manage position for the respawn system
//////////////////////////////////////////////////////////////
void parallax::respawn() noexcept {
  if (this->posX < -2000)
    this->posX = 1920;
  if (this->posX2 < -2000)
    this->posX2 = 1920;
  if (this->starPosX < -1920)
    this->starPosX = 1920;
  if (this->starPosX2 < -1920)
    this->starPosX2 = 1920;
}

//////////////////////////////////////////////////////////////
///@brief Draw parallax sprite and manage transition events
///@param window Window for Sfml content
///@param blackBack,  time in milisecond for black transition, (not too short or
///change opacityInc)
///@param mecaBlack,  time in milisecond for 2nd transition, Meca back, (not too
///short or change opacityInc)
//////////////////////////////////////////////////////////////
void parallax::parallaxManage(sf::RenderWindow &window, int blackBack,
                              int mecaBack) {
  window.draw(this->back1);
  window.draw(this->back2);
  window.draw(this->spriteStarStageOne1);
  window.draw(this->spriteStarStageOne2);
  window.draw(this->blackRectangle);
  position();
  respawn();
  if (this->clock.getElapsedTime().asMilliseconds() >= blackBack) {
    if (this->clock.getElapsedTime().asMilliseconds() >= mecaBack) {
      if (this->opacity > 0)
        this->opacity--;
      this->blackRectangle.setFillColor(sf::Color(0, 0, 0, this->opacity));
    }
    this->blackRectangle.setFillColor(sf::Color(0, 0, 0, this->opacity));
    if (this->opacity < 255 && this->state == false)
      this->opacity++;
    else {
      this->state = true;
      this->back1.setTexture(this->texture2);
      this->back2.setTexture(this->texture2);
      this->spriteStarStageOne1.setColor(sf::Color(0, 0, 0, 0));
      this->spriteStarStageOne2.setColor(sf::Color(0, 0, 0, 0));
    }
  }
}
