/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Sound
*/

#include "Registry.hpp"
#include <SFML/Audio.hpp>

#pragma once

namespace rt {

    struct Sound_t
    {
        sf::SoundBuffer buffer1;
        sf::SoundBuffer buffer2;
        sf::SoundBuffer buffer3;
        sf::Sound sound1;
        sf::Sound sound2;
        sf::Sound sound3;
        float volume = 100.0;
        bool state = false;
        bool state1 = true;
        bool state2 = true;
        bool state3 = true;
    };

    void SoundSystem(rt::Registry &);
};
