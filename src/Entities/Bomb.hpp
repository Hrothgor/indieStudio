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
            Bomb(Entity entity, ParticleSystem smokeBomb, ParticleSystem explosionBomb,  Color color1, Color color2);
            ~Bomb();

            void explode(Map &map);
            bool update(Camera3D camera, Map &map);

        protected:
        private:
            Clock _life;
            int _lifeLenght = 3;
            ParticleSystem _smokeBomb;
            ParticleSystem _explosionBomb;
    };
}

#endif /* !BOMB_HPP_ */
