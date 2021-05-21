/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomberman
*/

#pragma once
#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include "../global.hpp"
#include "Bomb.hpp"
#include "../Particles/ParticleSystem.hpp"

namespace IS {
    typedef struct keyPlayer_s {
        KeyboardKey up;
        KeyboardKey down;
        KeyboardKey left;
        KeyboardKey right;
        KeyboardKey bomb;
    } keyPlayer_t;

    class Bomberman : public Entity {
        public:
            Bomberman(Entity entity, ParticleSystem smokeFeet);
            Bomberman(Entity entity, ParticleSystem smokeFeet, keyPlayer_t keys);
            ~Bomberman();

            void checkKeyPressed();
            void changeModelRotation();
            void checkCollisionMap(Map &map);
            bool update(Camera3D camera, Map &map);

        protected:
        private:
            ParticleSystem _smokeFeet;
            Clock _animationClock;
            bool _IsAI;
            keyPlayer_t _keys;
    };
}

#endif /* !BOMBERMAN_HPP_ */
