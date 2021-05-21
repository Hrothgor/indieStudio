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
    class Bomberman : public Entity {
        public:
            Bomberman(Entity entity, ParticleSystem smokeFeet, bool IsAI);
            ~Bomberman();

            void changeModelRotation();
            void checkCollisionMap(Map map);
            void dropBomb();
            bool update(Camera3D camera, Map map);

        protected:
        private:
            ParticleSystem _smokeFeet;
            Clock _animationClock;
            bool _IsAI;
    };
}

#endif /* !BOMBERMAN_HPP_ */
