/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#pragma once
#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "../include.hpp"
#include "Entity.hpp"
#include "../Particles/ParticleSystem.hpp"

namespace IS {
    class Bomb : public Entity {
        public:
            Bomb(Entity entity, ParticleSystem &smokeBomb, ParticleSystem &explosionBomb);
            ~Bomb();

            bool update();

        protected:
        private:
            ParticleSystem _smokeBomb;
            ParticleSystem _explosionBomb;
    };
}

#endif /* !BOMB_HPP_ */
