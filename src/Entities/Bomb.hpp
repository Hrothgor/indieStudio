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
#include "Bomberman.hpp"
#include "../Particles/ParticleSystem.hpp"

namespace IS {
    class Bomb : public Entity {
        public:
            Bomb(Entity entity, Bomberman *player, ParticleSystem smokeBomb, ParticleSystem explosionBomb);
            ~Bomb();

            void checkKillPlayer(int x, int y, Camera *camera);
            void explode(Camera *camera);
            bool update(Camera *camera);

        protected:
        private:
            float _lifeLenght = 3;
            Bomberman *_player;
            ParticleSystem _smokeBomb;
            ParticleSystem _explosionBomb;
    };
}

#endif /* !BOMB_HPP_ */
