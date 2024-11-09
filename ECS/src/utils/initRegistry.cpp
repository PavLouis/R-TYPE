/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** initRegistry
*/

#include <SFML/Network.hpp>
#include <thread>

#include "EntityTypes.hpp"
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
#include "RT_ShootsMulti.hpp"
#include "RT_Size.hpp"
#include "RT_Music.hpp"
#include "RT_Velocity.hpp"
#include "RT_parallax.hpp"
#include "Registry.hpp"
#include "entitySend.hpp"
#include "sfServeur.hpp"

void initComponents(rt::Registry &r) noexcept {
  r.registerComponent<rt::EnemyBot>();
  r.registerComponent<rt::ShootsMulti>();
  r.registerComponent<rt::CollisionMulti>();
  r.registerComponent<rt::Paramov_t>();
  r.registerComponent<rt::Collision_t>();
  r.registerComponent<rt::Controllable_t>();
  r.registerComponent<rt::Drawable>();
  r.registerComponent<rt::Health_t>();
  r.registerComponent<rt::Hitbox_t>();
  r.registerComponent<rt::Direction_t>();
  r.registerComponent<rt::Velocity_t>();
  r.registerComponent<rt::Pos_t>();
  r.registerComponent<rt::Size_t>();
  r.registerComponent<rt::Shoots_t>();
  r.registerComponent<rt::Music_t>();
}