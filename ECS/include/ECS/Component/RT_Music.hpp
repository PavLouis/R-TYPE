/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** RT_Music
*/

#include "Registry.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

#pragma once

namespace rt {

    /**
     * @brief Handle all music informations
    **/
    struct Music_t
    {
        sf::SoundBuffer buffer;
        sf::SoundBuffer buffer2;
        sf::Sound Music;
        sf::Sound Music2;
        float volume = 40.0;
        float volume2 = 0.0;
        bool state = false;
    };

    void MusicSystem(rt::Registry &);
};
