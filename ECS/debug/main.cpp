/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** main.cpp
*/

#include "Registry.hpp"
#include "RT_Drawable.hpp"
#include "RT_Position.hpp"
#include "RT_Size.hpp"
#include "RT_Collision.hpp"
#include "RT_Controllable.hpp"
#include "RT_Health.hpp"
#include "RT_Hitbox.hpp"
#include "RT_Direction.hpp"
#include "RT_Velocity.hpp"
#include "RT_Shoots.hpp"
#include "RT_Music.hpp"
#include "RT_Enemy.hpp"
#include "RT_CollisionMulti.hpp"
#include "Systems.hpp"
#include "parallax.hpp"

#include "Loader.hpp"

int main(int const argc, char const * const * const argv)
{
    rt::Registry r;
    Entity player = r.spawnEntity();
    parallax para;
    // Entity background = r.spawnEntity();

    r.registerComponent<rt::Collision_t>();
    r.registerComponent<rt::EnemyBot>();
    r.registerComponent<rt::CollisionMulti>();
    r.registerComponent<rt::Controllable_t>();
    r.registerComponent<rt::Drawable>();
    r.registerComponent<rt::Health_t>();
    r.registerComponent<rt::Hitbox_t>();
    r.registerComponent<rt::Velocity_t>();
    r.registerComponent<rt::Direction_t>();
    r.registerComponent<rt::Pos_t>();
    r.registerComponent<rt::Size_t>();
    r.registerComponent<rt::Shoots_t>();
    r.registerComponent<rt::Music_t>();

    Loader t;
    t.setTextureFromFile("./Assets/Sprites/r-typesheet42.gif", "player");
    t.setTextureFromFile("./Assets/Sprites/r-typesheet3.gif", "shoot");
    t.setTextureFromFile("./Assets/Sprites/r-typesheet5.gif", "enemy1");
    // t.setTextureFromFile("./Assets/Sprites/bg.jpeg", "background");

    std::vector<std::string> c_v; c_v.push_back("Wall");
    r.addComponent(player, rt::Collision_t({c_v}));
    r.addComponent(player, rt::Controllable_t({sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Space, sf::Keyboard::E}));
    r.addComponent(player, rt::Drawable(t.get("player"), {{0, 0, 40, 40}}, sf::Int32(30), 1, sf::Vector2f(1, 1)));
    r.addComponent(player, rt::Music_t());
    std::vector<std::string> d_v; d_v.push_back("Player");
    r.addComponent(player, rt::Health_t({1}));
    r.addComponent(player, rt::Hitbox_t({40, 40}));
    r.addComponent(player, rt::Direction_t({0, 0}));
    r.addComponent(player, rt::Velocity_t({0, 0}));
    r.addComponent(player, rt::Pos_t({20, 20}));
    r.addComponent(player, rt::Size_t({40, 40}));
    std::vector<rt::Shoot_t> s_v; s_v.push_back({"shoot", {1, 0}, 0.01f, 200, sf::Clock()});
    r.addComponent(player, rt::Shoots_t({s_v}));
    // r.addComponent(background, rt::Pos_t({0, 0}));
    // r.addComponent(background, rt::Size_t({1920, 1080}));
    // rt::Drawable d(t.get("background"), {0, 0, 1920, 1080}, sf::Time());
    // r.addComponent(background, rt::Drawable(d));

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (clock.getElapsedTime().asMilliseconds() >= (1000 / 60)) {
            window.clear();
            // SpawnItem(r, t);
            para.parallaxManage(window, 10000, 20000);
            rt::DirectionSystem(r);
            rt::PositionSystem(r);
            rt::ControllableSystem(r, t);
            rt::DrawableSystem(r, window);
            rt::MusicSystem(r);
            //rt::SoundSystem(r);
            clock.restart();
        }
    }
    return (0);
}